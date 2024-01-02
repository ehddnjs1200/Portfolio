cbuffer Action : register(b0)
{
	float2 size;
	float2 startPos;
	float2 maxSize;
	float2 padding;
}

Texture2D map : register(t0);
SamplerState samp : register(s0);

struct PixelInput
{
	float4 pos : SV_POSITION;
	float2 uv : UV;
};

float4 PS(PixelInput input) : SV_TARGET
{
	float2 uv;

	uv.x = input.uv.x / (maxSize.x / size.x) + (startPos.x / maxSize.x);
	uv.y = input.uv.y / (maxSize.y / size.y) + (startPos.y / maxSize.y);

	return map.Sample(samp, uv);
}