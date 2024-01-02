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
    bd.Usage = D3D11_USAGE_DEFAULT;         // 버퍼읽고쓰기 방식
    bd.ByteWidth = _stride * _count;      // 버퍼의 크기(정점 좌표가 3개)
    bd.BindFlags = D3D11_BIND_INDEX_BUFFER;// 버퍼가 바인딩 되는 방법(꼭지점 버퍼로 입력)

    // 버퍼에 초기화에 사용될 정보
    D3D11_SUBRESOURCE_DATA initData;
    initData.pSysMem = data;

    // 버퍼 생성
    DEVICE->CreateBuffer(&bd, &initData, _buffer.GetAddressOf());
}

void IndexBuffer::Set()
{
    DEVICE_CONTEXT->IASetIndexBuffer(_buffer.Get(), DXGI_FORMAT_R32_UINT, _offset);
}
