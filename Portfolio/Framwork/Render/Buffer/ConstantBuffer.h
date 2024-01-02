#pragma once
// 상수버퍼
// 쉐이더가 접근할수있는 다양한 자료를 저장한 버퍼
// 대표적으로 WVP
// World
// - 도형이 가지고있는 좌표
// - 월드 변환 행렬
// - 물체는 각각의 0,0,0값을 기준으로 가지고 있으며, 이것을 월드 좌표계로 옮겨야한다.
// - 로컬(물체의 좌표) + 월드 좌표를 더해서 월드 좌표 기준으로 로컬의 좌표를 구함
// View
// - 카메라
// - 2D에서 world와 차이가없음, 3D 카메라가 z좌표가 생겨 다양해짐
// Projection
// - 투영
// - 3차원 좌표계를 2차원 좌표계로 변환하는 행렬
// - 2D에서 활용 못함

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

