// HLSL
// High Level Shader Language(����� ���̴� ���)
// DirectX���� ���̴��� ���̵��Ҷ� ����ϴ� ���
// sv : System Value(�ø�ƽ)

//float4 VS( float4 pos : A ) : SV_POSITION
//{
//	return pos;
//}
//
//float4 PS() : SV_TARGET
//{
//	return float4(1.0f,0.7f,1.0f,1.0f); // RGBA
//}

// t : ���̴� ���ҽ� ��(SRV)��
// s : ���÷�������Ʈ��
// u : ������ ������ ��(UAV)
// b : ������ۺ�(CBV)
Texture2D map : register(t0);
SamplerState samp : register(s0);
// SV_POSITION(pos) = POSITION(POS)
// SV_TARGET = color

struct VertexInput
{
	float4 pos : POSITION;
	float2 uv : UV;
};

struct PixelInput
{
	float4 pos : SV_POSITION;
	float2 uv : UV;
};

PixelInput VS(VertexInput input)
{
	PixelInput output;
	output.pos = input.pos;
	output.uv = input.uv;

	return output;
}

// ��ĥ��
// 1�����Ӵ� ȣ��Ƚ���� , �׸��� �ػ󵵸�ŭ ȣ��
float4 PS(PixelInput input) : SV_TARGET
{
	/*float4 result = map.Sample(samp, input.uv);
	result.b = 0.5f;

	return result;*/

	return map.Sample(samp, input.uv);
}