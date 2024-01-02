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
    // Vertex 버퍼 : vertexShader에서 일 할 때 필요한 정보를 넘겨주는것
    D3D11_BUFFER_DESC bd = {};
    bd.Usage = D3D11_USAGE_DEFAULT;         // 버퍼읽고쓰기 방식
    bd.ByteWidth = _stride * _count;      // 버퍼의 크기(정점 좌표가 3개)
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;// 버퍼가 바인딩 되는 방법(꼭지점 버퍼로 입력)

    // 버퍼에 초기화에 사용될 정보
    D3D11_SUBRESOURCE_DATA initData;
    //initData.pSysMem = vertices;
    initData.pSysMem = data;

    // 버퍼 생성
    DEVICE->CreateBuffer(&bd, &initData, _buffer.GetAddressOf());
}
