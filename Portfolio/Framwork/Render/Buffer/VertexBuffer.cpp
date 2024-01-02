#include "framework.h"
#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(void* data, UINT stride, UINT count, UINT offset)
: _stride(stride)
, _count(count)
, _offset(offset)
{
	CreateVertexBuffer(data);
}

VertexBuffer::~VertexBuffer()
{
}

void VertexBuffer::Set(int slot)
{
    DEVICE_CONTEXT->IASetVertexBuffers(slot, 1, _buffer.GetAddressOf(), &_stride, &_offset);
}

void VertexBuffer::CreateVertexBuffer(void* data)
{
    // Vertex ���� : vertexShader���� �� �� �� �ʿ��� ������ �Ѱ��ִ°�
    D3D11_BUFFER_DESC bd = {};
    bd.Usage = D3D11_USAGE_DEFAULT;         // �����а��� ���
    bd.ByteWidth = _stride * _count;      // ������ ũ��(���� ��ǥ�� 3��)
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;// ���۰� ���ε� �Ǵ� ���(������ ���۷� �Է�)

    // ���ۿ� �ʱ�ȭ�� ���� ����
    D3D11_SUBRESOURCE_DATA initData;
    //initData.pSysMem = vertices;
    initData.pSysMem = data;

    // ���� ����
    DEVICE->CreateBuffer(&bd, &initData, _buffer.GetAddressOf());
}
