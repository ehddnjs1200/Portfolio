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
    sd.BufferCount = 1;                 // buffer ����
    sd.BufferDesc.Width = WIN_WIDTH;        // buffer ��
    sd.BufferDesc.Height = WIN_HEIGHT;      // buffer ����
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM; // RGB�� 8��Ʈ�� 4���Ͽ� 32��Ʈ ��ȣ���� ���������� ���
    sd.BufferDesc.RefreshRate.Numerator = 60; // ȭ�� ���ŷ�(������)
    sd.BufferDesc.RefreshRate.Denominator = 1; // �и�
    // ������ = ���÷��� ��� �ֻ��� (Numerator/Denominator)
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; // ��¿� ���۷� ���ڴٰ� ����
    sd.OutputWindow = hWnd;
    sd.SampleDesc.Count = 1;   // �ȼ��� ����
    sd.SampleDesc.Quality = 0; // ǰ��
    sd.Windowed = true;

    D3D11CreateDeviceAndSwapChain(
        nullptr,                    // �׷���ī�� �����, nullptr�� ���� ���� ������� �׷���ī�尡 ��
        D3D_DRIVER_TYPE_HARDWARE,   // �ϵ���� ���ؿ� �´� ��� ����
        0,                          // � �߰����� ���� �ٰ���
        D3D11_CREATE_DEVICE_DEBUG | D3D11_CREATE_DEVICE_BGRA_SUPPORT,  // ����� ���� ����
        featureLevels,              // ���ķ��� �迭
        featureSize,                // ���ķ��� ������
        D3D11_SDK_VERSION,          // SDK ����
        &sd,                        // ����ü�� ���� ����ü
        _swapChain.GetAddressOf(),  // ����ü�� ��ü
        _device.GetAddressOf(),     // ����̽� ��ü
        nullptr,                    // ������ ���ķ��� ����(���ο��)
        _deviceContext.GetAddressOf() // ����̽� ���ؽ�Ʈ ��ü
    );
}

void Device::CreateBackBuffer()
{
    ComPtr<ID3D11Texture2D> backBuffer;

    _swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)backBuffer.GetAddressOf());
    _device->CreateRenderTargetView(backBuffer.Get(), nullptr, _renderTargetView.GetAddressOf());
    _deviceContext->OMSetRenderTargets(1, _renderTargetView.GetAddressOf(), nullptr);

    D3D11_VIEWPORT vp = {};
    vp.Width = WIN_WIDTH;       // ����Ʈ ����
    vp.Height = WIN_HEIGHT;     // ����Ʈ ����
    vp.MinDepth = 0.0f;     // ����Ʈ ���̰��� �ּ�
    vp.MaxDepth = 1.0f;     // ����Ʈ ���̰��� �ִ�
    vp.TopLeftX = 0.0f;     // ����Ʈ�� X��ǥ
    vp.TopLeftY = 0.0f;     // ����Ʈ�� Y��ǥ
    _deviceContext->RSSetViewports(1, &vp);
}

void Device::ClearColor()
{
    // ����
    //FLOAT ColorR = 184.0f / 255.0f;
    //FLOAT ColorG = 248.0f / 255.0f;
    //FLOAT ColorB = 251.0f / 255.0f;
    //FLOAT Color[4] = { ColorR, ColorG, ColorB, 1.0f };

    FLOAT Color[4] = {0.1f,0.1f,0.1f,1.0f};

    // ���� �ֱ�
    _deviceContext->ClearRenderTargetView(_renderTargetView.Get(), Color);
}

void Device::Present()
{
    _swapChain->Present(0, 0);
}
