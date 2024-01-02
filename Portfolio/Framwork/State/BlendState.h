#pragma once
// ���� ������Ʈ
// blend = ȥ��
// ���İ��� �����ϴ°�(����� ����̸� �ƿ� �Ⱥ��ϼ��� ����)
// �ȼ����̴����� ��µ� �ȼ���(SRC)�� ����Ÿ���� ��(DEST)�� ���� �����Ѱ�
// SRC * SRC, DEST * DEST

class BlendState
{
public:
	BlendState();
	~BlendState();

	void CreateState();
	void SetState();

	void Alpha();
	void Additive();

	void Change();


private:
	ComPtr<ID3D11BlendState>	_state;
	D3D11_BLEND_DESC			_desc;

};

