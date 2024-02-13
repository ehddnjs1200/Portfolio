#include "framework.h"
#include "DXWrite.h"

DXWrite* DXWrite::_instance = nullptr;

DXWrite::DXWrite()
{
	// 1. 팩토리 생성
	// __uuidof : GUI ID의 값을 리턴해줌
	// IUnknown : Comptr의 인터페이스를 지원
	assert(SUCCEEDED(DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED,
		__uuidof(IDWriteFactory), (IUnknown**)_writeFactory.GetAddressOf())));

	// 여러쓰레드를 사용하겠다.
	assert(SUCCEEDED(D2D1CreateFactory(D2D1_FACTORY_TYPE_MULTI_THREADED, _factory.GetAddressOf())));

	ComPtr<IDXGIDevice> dxgiDevice;
	assert(SUCCEEDED(DEVICE->QueryInterface(dxgiDevice.GetAddressOf())));

	// 변수로 만든 디바이스와 factory 연결
	assert(SUCCEEDED(_factory->CreateDevice(dxgiDevice.Get(), _device.GetAddressOf())));

	assert(SUCCEEDED(_device->CreateDeviceContext(D2D1_DEVICE_CONTEXT_OPTIONS_ENABLE_MULTITHREADED_OPTIMIZATIONS,
		_deviceContext.GetAddressOf())));

	// 스왑체인
	ComPtr<IDXGISurface> dxgiSurface;
	assert(SUCCEEDED(Device::GetInstance()->GetSwapChain()->GetBuffer(0, __uuidof(IDXGISurface),
		(void**)dxgiSurface.GetAddressOf())));

	// 비트맵옵션
	D2D1_BITMAP_PROPERTIES1 bp;
	bp.pixelFormat.format = DXGI_FORMAT_R8G8B8A8_UNORM; // 형식 및 알파 모드
	bp.pixelFormat.alphaMode = D2D1_ALPHA_MODE_IGNORE; // 알파값 무시
	// dot per inch(기본값 96)
	bp.dpiX = 96.0f;
	bp.dpiY = 96.0f;
	// 비트맵과 컨텍스트를 연결/ 상수화(초기값으로 고정된값)
	bp.bitmapOptions = D2D1_BITMAP_OPTIONS_TARGET | D2D1_BITMAP_OPTIONS_CANNOT_DRAW;
	bp.colorContext = nullptr;

	assert(SUCCEEDED(_deviceContext->CreateBitmapFromDxgiSurface(dxgiSurface.Get(), &bp, _targetBitMap.GetAddressOf())));

	// 비트맵으로 타켓잡기
	_deviceContext->SetTarget(_targetBitMap.Get());
}

DXWrite::~DXWrite()
{
}

void DXWrite::RenderText(wstring text, RECT rect, float fontSize, wstring font, XMFLOAT4 color, DWRITE_FONT_WEIGHT weight, DWRITE_FONT_STYLE style, DWRITE_FONT_STRETCH stretch)
{
	// 2. 텍스트연결
	RECT aRect = rect;
	FontBrushDesc brushDesc;
	brushDesc._color = color;

	FontBrushDesc* findBrush = nullptr;
	for (FontBrushDesc& desc : _fontBrushes)
	{
		if (desc == brushDesc)
		{
			findBrush = &desc;
			break;
		}
	}

	if (findBrush == nullptr)
	{
		D2D1::ColorF colorF = D2D1::ColorF(color.x, color.y, color.z);
		_deviceContext->CreateSolidColorBrush(colorF, brushDesc._brush.GetAddressOf());
		_fontBrushes.emplace_back(brushDesc);
		findBrush = &brushDesc;
	}

	FontTextDesc textDesc;
	textDesc._font = font;
	textDesc._fontSize = fontSize;
	textDesc._weight = weight;
	textDesc._style = style;
	textDesc._stretch = stretch;

	FontTextDesc* findText = nullptr;
	for (auto& desc : _fontTexts)
	{
		if (desc == textDesc)
		{
			findText = &desc;
			break;
		}
	}

	if (findText == nullptr)
	{
		assert(SUCCEEDED(_writeFactory->CreateTextFormat(textDesc._font.c_str(), nullptr,
			textDesc._weight, textDesc._style, textDesc._stretch,
			textDesc._fontSize, L"ko", textDesc._format.GetAddressOf())));
		// en-us, ko-kr, ja-jp

		_fontTexts.emplace_back(textDesc);
		findText = &textDesc;
	}

	D2D1_RECT_F rectF;
	rectF.left = rect.left;
	rectF.right = rect.right;
	rectF.top = rect.top;
	rectF.bottom = rect.bottom;

	// 3. 렌더타겟에 연결해 보여주기
	_deviceContext->DrawTextW(text.c_str(), text.size(), findText->_format.Get(),
		&rectF, findBrush->_brush.Get());
}