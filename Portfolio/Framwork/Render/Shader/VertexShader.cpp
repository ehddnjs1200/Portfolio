#include "framework.h"
#include "VertexShader.h"

VertexShader::VertexShader(wstring file)
{
    CreateShader(file);
}

VertexShader::~VertexShader()
{
}

void VertexShader::CreateShader(wstring file)
{
    DWORD flags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;

    // ������ ����ü
    D3D11_INPUT_ELEMENT_DESC layout[] =
    {
        // ������ ���̴� ������, �ε��� ��ȣ, ���� ������ �ڷ� ����, ���۽���, ������ġ, �ν��Ͻ�, �ν��Ͻ�
            {
                "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0
            },
            {
                "UV", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0
            }
    };
    UINT layoutSize = ARRAYSIZE(layout);
    wstring filename = L"Shaders/" + file + L".hlsl";
    D3DCompileFromFile(filename.data(), nullptr, nullptr, "VS", "vs_5_0", flags, 0, _blob.GetAddressOf(), nullptr);
    DEVICE->CreateInputLayout(layout, layoutSize, _blob->GetBufferPointer(), _blob->GetBufferSize(), _inputLayout.GetAddressOf());
    DEVICE->CreateVertexShader(_blob->GetBufferPointer(), _blob->GetBufferSize(), nullptr, _shader.GetAddressOf());
}

void VertexShader::Set()
{
    DEVICE_CONTEXT->IASetInputLayout(_inputLayout.Get());
    DEVICE_CONTEXT->VSSetShader(_shader.Get(), nullptr, 0);
}
