#include "framework.h"
#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(void* data, UINT stride, UINT count, UINT offset)
: _stride(stride)
, _count(count)
, _offset(offset)
{
	CreateIndexBuffer(data);
}

IndexBuffer::~IndexBuffer()
{
}

void IndexBuffer::CreateIndexBuffer(void* data)
{
    D3D11_BUFFER_DESC bd = {};
    bd.Usage = D3D11_USAGE_DEFAULT;         // �����а��� ���
    bd.ByteWidth = _stride * _count;      // ������ ũ��(���� ��ǥ�� 3��)
    bd.BindFlags = D3D11_BIND_INDEX_BUFFER;// ���۰� ���ε� �Ǵ� ���(������ ���۷� �Է�)

    // ���ۿ� �ʱ�ȭ�� ���� ����
    D3D11_SUBRESOURCE_DATA initData;
    initData.pSysMem = data;

    // ���� ����
    DEVICE->CreateBuffer(&bd, &initData, _buffer.GetAddressOf());
}

void IndexBuffer::Set()
{
    DEVICE_CONTEXT->IASetIndexBuffer(_buffer.Get(), DXGI_FORMAT_R32_UINT, _offset);
}
