#include "framework.h"
#include "Device.h"

Device* Device::_instance = nullptr;

Device::Device(HWND hWnd)
{
	CreateDeviceAndSwapChain();
    CreateBackBuffer();
}

Device::~Device()
{
}

void Device::CreateDeviceAndSwapChain()
{
    D3D_FEATURE_LEVEL featureLevels[] =
    {
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_0,
        D3D_FEATURE_LEVEL_10_1,
    };

    UINT featureSize = ARRAYSIZE(featureLevels);

    DXGI_SWAP_CHAIN_DESC sd = {};
    sd.BufferCount = 1;                 // buffer 개수
    sd.BufferDesc.Width = WIN_WIDTH;        // buffer 폭
    sd.BufferDesc.Height = WIN_HEIGHT;      // buffer 높이
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM; // RGB를 8비트로 4개하여 32비트 부호없는 정수형으로 사용
    sd.BufferDesc.RefreshRate.Numerator = 60; // 화면 갱신률(프레임)
    sd.BufferDesc.RefreshRate.Denominator = 1; // 분모
    // 프레임 = 디스플레이 모드 주사율 (Numerator/Denominator)
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; // 출력용 버퍼로 쓰겠다고 지정
    sd.OutputWindow = hWnd;
    sd.SampleDesc.Count = 1;   // 픽셀의 개수
    sd.SampleDesc.Quality = 0; // 품질
    sd.Windowed = true;

    D3D11CreateDeviceAndSwapChain(
        nullptr,                    // 그래픽카드 어떤쓸지, nullptr을 쓰면 내가 사용중인 그래픽카드가 들어감
        D3D_DRIVER_TYPE_HARDWARE,   // 하드웨어 수준에 맞는 기술 적용
        0,                          // 어떤 추가적인 값은 줄건지
        D3D11_CREATE_DEVICE_DEBUG | D3D11_CREATE_DEVICE_BGRA_SUPPORT,  // 디버그 정보 생성
        featureLevels,              // 피쳐레벨 배열
        featureSize,                // 피쳐레벨 사이즈
        D3D11_SDK_VERSION,          // SDK 버전
        &sd,                        // 스왑체인 생성 구조체
        _swapChain.GetAddressOf(),  // 스왑체인 객체
        _device.GetAddressOf(),     // 디바이스 객체
        nullptr,                    // 생성된 피쳐레벨 정보(새로운것)
        _deviceContext.GetAddressOf() // 디바이스 컨텍스트 객체
    );
}

void Device::CreateBackBuffer()
{
    ComPtr<ID3D11Texture2D> backBuffer;

    _swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)backBuffer.GetAddressOf());
    _device->CreateRenderTargetView(backBuffer.Get(), nullptr, _renderTargetView.GetAddressOf());
    _deviceContext->OMSetRenderTargets(1, _renderTargetView.GetAddressOf(), nullptr);

    D3D11_VIEWPORT vp = {};
    vp.Width = WIN_WIDTH;       // 뷰포트 넓이
    vp.Height = WIN_HEIGHT;     // 뷰포트 높이
    vp.MinDepth = 0.0f;     // 뷰포트 깊이값의 최소
    vp.MaxDepth = 1.0f;     // 뷰포트 깊이값의 최대
    vp.TopLeftX = 0.0f;     // 뷰포트의 X좌표
    vp.TopLeftY = 0.0f;     // 뷰포트의 Y좌표
    _deviceContext->RSSetViewports(1, &vp);
}

void Device::ClearColor()
{
    // 배경색
    //FLOAT ColorR = 184.0f / 255.0f;
    //FLOAT ColorG = 248.0f / 255.0f;
    //FLOAT ColorB = 251.0f / 255.0f;
    //FLOAT Color[4] = { ColorR, ColorG, ColorB, 1.0f };

    FLOAT Color[4] = {0.1f,0.1f,0.1f,1.0f};

    // 배경색 넣기
    _deviceContext->ClearRenderTargetView(_renderTargetView.Get(), Color);
}

void Device::Present()
{
    _swapChain->Present(0, 0);
}
