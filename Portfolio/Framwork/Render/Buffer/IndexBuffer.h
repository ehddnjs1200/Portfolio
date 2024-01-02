#pragma once
class IndexBuffer
{
public:
	IndexBuffer(void* data, UINT stride, UINT count, UINT offset = 0);
	~IndexBuffer();

	void CreateIndexBuffer(void* data);
	void Set();

private:
	ComPtr<ID3D11Buffer> _buffer;

	UINT _stride;
	UINT _count;
	UINT _offset;
};

