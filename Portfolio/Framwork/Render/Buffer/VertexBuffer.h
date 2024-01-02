#pragma once
// ���ؽ� ����
// - ������ ������ �����صδ� ����

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

