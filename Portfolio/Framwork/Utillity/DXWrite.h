#pragma once
// 색깔용
struct FontBrushDesc
{
	XMFLOAT4 _color;
	ComPtr<ID2D1SolidColorBrush> _brush;

	bool operator==(const FontBrushDesc& value)
	{
		return _color.x == value._color.x && _color.y == value._color.y &&
			_color.z == value._color.z && _color.w == value._color.w;
	}
};

// 폰트
struct FontTextDesc
{
	wstring _font;
	float _fontSize;

	DWRITE_FONT_WEIGHT	_weight;
	DWRITE_FONT_STYLE	_style;
	DWRITE_FONT_STRETCH	_stretch; // 간격

	ComPtr<IDWriteTextFormat> _format; // 폰트와 관련된 모든것을 관리

	bool operator==(const FontTextDesc& value)
	{
		bool b = true;

		b &= (_font == value._font);
		b &= (_fontSize == value._fontSize);
		b &= (_weight == value._weight);
		b &= (_style == value._style);
		b &= (_stretch == value._stretch);

		return b;
	}
};

class DXWrite
{
private:
	DXWrite();
	~DXWrite();

public:
	static void Create()
	{
		if (_instance == nullptr)
			_instance = new DXWrite();
	}
	static void Delete()
	{
		if (_instance != nullptr)
			delete _instance;
	}
	static DXWrite* GetInstance()
	{
		if (_instance != nullptr)
			return _instance;
	}

	void RenderText(wstring text, RECT rect, float fontSize = 20.0f,
		wstring font = L"굴림",
		XMFLOAT4 color = XMFLOAT4(1, 1, 0, 1),
		DWRITE_FONT_WEIGHT weight = DWRITE_FONT_WEIGHT_NORMAL, // 글꼴 두께 : 보통(400)
		DWRITE_FONT_STYLE style = DWRITE_FONT_STYLE_NORMAL,    // 글꼴 스타일 : 보통
		DWRITE_FONT_STRETCH stretch = DWRITE_FONT_STRETCH_NORMAL // 글꼴 간격 : 보통
	);

	ComPtr<ID2D1DeviceContext> GetDeviceContext() { return _deviceContext; }

private:
	static DXWrite* _instance;

	ComPtr<ID2D1Factory1>	_factory;
	ComPtr<IDWriteFactory>	_writeFactory;

	ComPtr<ID2D1Device>			_device;
	ComPtr<ID2D1DeviceContext>	_deviceContext;
	ComPtr<ID2D1Bitmap1>		_targetBitMap;

	vector<FontBrushDesc>		_fontBrushes;
	vector<FontTextDesc>		_fontTexts;
};