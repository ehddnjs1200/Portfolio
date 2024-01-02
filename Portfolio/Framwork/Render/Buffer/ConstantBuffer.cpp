#include "framework.h"
#include "ConstantBuffer.h"

ConstantBuffer::ConstantBuffer(void* data, UINT dataSize)
: _data(data)
, _dataSize(dataSize)
{
	CreateBuffer();
}

ConstantBuffer::~ConstantBuffer()
{
}

void ConstantBuffer::Update()
{
	DEVICE_CONTEXT->UpdateSubresource(_buffer.Get(), 0, nullptr, _data, 0, 0);
}

void ConstantBuffer::CreateBuffer()
{
	D3D11_BUFFER_DESC bd = {};
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = _dataSize;
	bd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;

	DEVICE->CreateBuffer(&bd, nullptr, _buffer.GetAddressOf());
}

void ConstantBuffer::SetVsBuffer(int slot)
{
	DEVICE_CONTEXT->VSSetConstantBuffers(slot, 1, _buffer.GetAddressOf());
	Update();
}

void ConstantBuffer::SetPsBuffer(int slot)
{
	DEVICE_CONTEXT->PSSetConstantBuffers(slot, 1, _buffer.GetAddressOf());
	Update();
}
