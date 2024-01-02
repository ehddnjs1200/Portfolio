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
// alpha, additive �� �ΰ��� �����.
	_desc.AlphaToCoverageEnable = false;
	_desc.IndependentBlendEnable = false;

	// ����Ÿ�� ������ �ִ� 8��
	// ����Ÿ�� ���� ������ ���������ο��� ��� �ܰ��
	// OM(OutPut Merge), Color Blend
	_desc.RenderTarget[0].BlendEnable = true; // ���ĸ� �����ϰڴ�. ���� Ÿ���� 0�� ����ϰڴ�

	// srcBlend, DestBlend, BlendOp �Ѽ�Ʈ
	// srcBlend �ȼ� ���̴��� ��µ� RGB��
	// DestBlend ���� ���� Ÿ���� RGB��
	// BlendOp src�� Dest�� ��� �������� �� ������ ���� ����

	_desc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
	// ȥ�ѿ�Ҵ� �ȼ� ���̴��� ���� ������(A)�� (As, As, As, As), ���� ȥ�� �۾��� �����ϴ�.
	// ���� Ÿ�ٿ� ����� �̹����� ������ �������� ���ϰڴ�.
	_desc.RenderTarget[0].DestBlend = D3D11_BLEND_ONE;
	// ȥ�� ����� (0,0,0,0)�Դϴ�. ���� ȥ�� �۾��� �����ϴ�.
	// �޹�濡�� ����� �̹��� alpha�� ������ ����
	_desc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
	// ���Ŀ����� �������� �ϰڴ�.
	// ���� 1 �� ���� 2�� �߰�

	// SrcBlendAlpha, DestBlendAlpha, BlendOpAlpha �Ѽ�Ʈ
	// SrcBlendAlpha�� �ȼ� ���̴��� ��µ� Alpha��
	// DestBlendAlpha�� ���� ���� Ÿ���� Alpha��
	// BlendOpAlpha�� �� ���ĸ� ��� �������� �� ������ ���� ����

	_desc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ZERO;
	_desc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
	_desc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;

	// RGB�� ��簪�� �� ���ڴ�.
	_desc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;

	//Change();
}

void BlendState::SetState()
{
	float blendFactor[] = {0.0f,0.0f,0.0f,0.0f}; // ���� �⺻���� �ʱ�ȭ
	DEVICE_CONTEXT->OMSetBlendState(_state.Get(), blendFactor, 0xffffffff);
	// 0xfffffff
	// int = -1
	// unsinged int = 4294967295
}

void BlendState::Alpha()
{
	// �����̹����� ���� ��� �̹����� ���� ȥ��
	// ȥ�հ���� �ȼ� ���̴��� ���� ������(A)�� (1-As,1-As,1-As,1-As)
	_desc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
	Change();
}

void BlendState::Additive()
{
	// ȥ�հ���� (1,1,1,1)
	_desc.RenderTarget[0].DestBlend = D3D11_BLEND_ONE;
	Change();
}

void BlendState::Change()
{
	// ���� ��ü ����
	DEVICE->CreateBlendState(&_desc, _state.GetAddressOf());
}
