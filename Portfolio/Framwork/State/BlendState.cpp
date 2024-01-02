#include "framework.h"
#include "BlendState.h"

BlendState::BlendState()
{
	CreateState();
}

BlendState::~BlendState()
{
}

void BlendState::CreateState()
{
// alpha, additive 이 두개를 꺼논다.
	_desc.AlphaToCoverageEnable = false;
	_desc.IndependentBlendEnable = false;

	// 렌더타겟 갯수가 최대 8개
	// 렌더타겟 과연 렌더링 파이프라인에서 어느 단계냐
	// OM(OutPut Merge), Color Blend
	_desc.RenderTarget[0].BlendEnable = true; // 알파를 연산하겠다. 렌더 타겟의 0만 사용하겠다

	// srcBlend, DestBlend, BlendOp 한세트
	// srcBlend 픽셀 쉐이더의 출력된 RGB값
	// DestBlend 현재 렌더 타겟의 RGB값
	// BlendOp src와 Dest를 어떻게 조합할지 즉 연산을 할지 설정

	_desc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
	// 혼한요소는 픽셀 쉐이더의 알파 데이터(A)인 (As, As, As, As), 사전 혼합 작업이 없습니다.
	// 렌더 타겟에 출력할 이미지가 가지는 불투명도를 곱하겠다.
	_desc.RenderTarget[0].DestBlend = D3D11_BLEND_ONE;
	// 혼한 계수는 (0,0,0,0)입니다. 사전 혼합 작업이 없습니다.
	// 뒷배경에다 출력항 이미지 alpha의 역수를 곱함
	_desc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
	// 알파연산을 덧셈으로 하겠다.
	// 원본 1 및 원본 2를 추가

	// SrcBlendAlpha, DestBlendAlpha, BlendOpAlpha 한세트
	// SrcBlendAlpha는 픽셀 쉐이더의 출력된 Alpha값
	// DestBlendAlpha는 현재 렌더 타겟의 Alpha값
	// BlendOpAlpha는 두 알파를 어떻게 조합할지 즉 연산을 할지 설정

	_desc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ZERO;
	_desc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
	_desc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;

	// RGB의 모든값을 다 쓰겠다.
	_desc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;

	//Change();
}

void BlendState::SetState()
{
	float blendFactor[] = {0.0f,0.0f,0.0f,0.0f}; // 색을 기본값을 초기화
	DEVICE_CONTEXT->OMSetBlendState(_state.Get(), blendFactor, 0xffffffff);
	// 0xfffffff
	// int = -1
	// unsinged int = 4294967295
}

void BlendState::Alpha()
{
	// 원본이미지의 색과 대상 이미지의 색이 혼합
	// 혼합계수는 픽셀 쉐이더의 알파 데이터(A)인 (1-As,1-As,1-As,1-As)
	_desc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
	Change();
}

void BlendState::Additive()
{
	// 혼합계수는 (1,1,1,1)
	_desc.RenderTarget[0].DestBlend = D3D11_BLEND_ONE;
	Change();
}

void BlendState::Change()
{
	// 블랜딩 객체 생성
	DEVICE->CreateBlendState(&_desc, _state.GetAddressOf());
}
