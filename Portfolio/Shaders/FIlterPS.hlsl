cbuffer IsRight : register(b0)
{
	int LR;
	int TB;
	int value2;
	int value3;
}

Texture2D map : register(t0);
SamplerState samp : register(s0);

struct PixelInput
{
	float4 pos : SV_POSITION;
	float2 uv : UV;
};

// color
float4 PS(PixelInput input) : SV_TARGET
{
	float4 result;

	if(LR == 1)
		input.uv.x = 1 - input.uv.x;
	if(TB == 1)
		input.uv.y = 1 - input.uv.y;

	result = map.Sample(samp, input.uv);

	return result;
}