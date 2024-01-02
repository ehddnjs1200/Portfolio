#pragma once
// 블랜드 스테이트
// blend = 혼합
// 알파값을 조정하는것(배경이 흰색이면 아예 안보일수도 있음)
// 픽셀쉐이더에서 출력된 픽셀값(SRC)과 렌더타겟의 값(DEST)를 각각 제곱한것
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

