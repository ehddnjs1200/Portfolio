cbuffer Button : register(b0)
{
	int state;
	float hovered;
	float clicked;
	float padding;
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
	float4 result;
	result = map.Sample(samp, input.uv);

	if (state == 0)
	{
		return result;
	}
	else if (state == 1)
	{
		float4 hoverColor = { hovered , hovered , hovered , 0.0f};
		result -= hoverColor;
		return result;
	}
	else if (state == 2)
	{
		float4 clickColor = { clicked , clicked , clicked , 0.0f };
		result -= clickColor;
		return result;
	}

	return result;

}