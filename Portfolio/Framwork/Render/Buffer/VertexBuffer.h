#pragma once
// 버텍스 버퍼
// - 정점의 정보를 저장해두는 버퍼

class VertexBuffer
{
public:
	VertexBuffer(void* data, UINT stride, UINT count, UINT offset = 0);
	~VertexBuffer();

	void Set(int slot);

private:
	void CreateVertexBuffer(void* data);

	ComPtr<ID3D11Buffer> _buffer;

	UINT _stride;
	UINT _count;
	UINT _offset;
};

