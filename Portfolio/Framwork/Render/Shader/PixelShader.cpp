#include "framework.h"
#include "PixelShader.h"

PixelShader::PixelShader(wstring file)
{
	CreateShader(file);
}

PixelShader::~PixelShader()
{
}

void PixelShader::CreateShader(wstring file)
{
	DWORD flags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;

	wstring filename = L"Shaders/" + file + L".hlsl";
	D3DCompileFromFile(filename.data(), nullptr, nullptr, "PS", "ps_5_0", flags, 0, _blob.GetAddressOf(), nullptr);
	DEVICE->CreatePixelShader(_blob->GetBufferPointer(), _blob->GetBufferSize(), nullptr, _shader.GetAddressOf());
}

void PixelShader::Set()
{
	DEVICE_CONTEXT->PSSetShader(_shader.Get(), nullptr, 0);
}
