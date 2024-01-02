#pragma once
// �������
// ���̴��� �����Ҽ��ִ� �پ��� �ڷḦ ������ ����
// ��ǥ������ WVP
// World
// - ������ �������ִ� ��ǥ
// - ���� ��ȯ ���
// - ��ü�� ������ 0,0,0���� �������� ������ ������, �̰��� ���� ��ǥ��� �Űܾ��Ѵ�.
// - ����(��ü�� ��ǥ) + ���� ��ǥ�� ���ؼ� ���� ��ǥ �������� ������ ��ǥ�� ����
// View
// - ī�޶�
// - 2D���� world�� ���̰�����, 3D ī�޶� z��ǥ�� ���� �پ�����
// Projection
// - ����
// - 3���� ��ǥ�踦 2���� ��ǥ��� ��ȯ�ϴ� ���
// - 2D���� Ȱ�� ����

class ConstantBuffer
{
public:
	ConstantBuffer(void* data, UINT dataSize);
	virtual ~ConstantBuffer();

	void Update();

	void CreateBuffer();

	void SetVsBuffer(int slot);
	void SetPsBuffer(int slot);

private:
	ComPtr<ID3D11Buffer> _buffer;

	void* _data;
	UINT _dataSize;
};

