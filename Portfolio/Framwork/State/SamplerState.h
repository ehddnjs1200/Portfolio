#pragma once
class SamplerState
{
public:
	SamplerState();
	~SamplerState();

	void CreateSamplerState();
	void SetState(int slot = 0);
private:
	ComPtr<ID3D11SamplerState> _samplerState;
};

