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
    sampDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT; // 텍스쳐를 샘플링할 필터링 방법
    sampDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP; // 0~1범위의 U 텍스쳐 좌표
    sampDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP; // 0~1범위의 V 텍스쳐 좌표
    sampDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP; // 0~1범위의 W 텍스쳐 좌표
    sampDesc.ComparisonFunc = D3D11_COMPARISON_NEVER; // 샘플링된 데이터와 기존 샘플링된 데이터를 비교
    sampDesc.MinLOD = -FLT_MAX;
    sampDesc.MaxLOD = FLT_MAX; // D3D11_FLOAT32_MAX

    DEVICE.Get()->CreateSamplerState(&sampDesc, _samplerState.GetAddressOf());
}

void SamplerState::SetState(int slot)
{
    DEVICE_CONTEXT->PSSetSamplers(slot, 1, _samplerState.GetAddressOf());
}
