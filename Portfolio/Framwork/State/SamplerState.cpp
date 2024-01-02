#include "framework.h"
#include "SamplerState.h"

SamplerState::SamplerState()
{
	CreateSamplerState();
}

SamplerState::~SamplerState()
{
}

void SamplerState::CreateSamplerState()
{
    D3D11_SAMPLER_DESC sampDesc = {};
    sampDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT; // �ؽ��ĸ� ���ø��� ���͸� ���
    sampDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP; // 0~1������ U �ؽ��� ��ǥ
    sampDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP; // 0~1������ V �ؽ��� ��ǥ
    sampDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP; // 0~1������ W �ؽ��� ��ǥ
    sampDesc.ComparisonFunc = D3D11_COMPARISON_NEVER; // ���ø��� �����Ϳ� ���� ���ø��� �����͸� ��
    sampDesc.MinLOD = -FLT_MAX;
    sampDesc.MaxLOD = FLT_MAX; // D3D11_FLOAT32_MAX

    DEVICE.Get()->CreateSamplerState(&sampDesc, _samplerState.GetAddressOf());
}

void SamplerState::SetState(int slot)
{
    DEVICE_CONTEXT->PSSetSamplers(slot, 1, _samplerState.GetAddressOf());
}
