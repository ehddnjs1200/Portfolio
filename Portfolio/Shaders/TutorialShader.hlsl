// HLSL
// High Level Shader Language(고수준 쉐이더 언어)
// DirectX에서 쉐이더를 쉐이딩할때 사용하는 언어
// sv : System Value(시맨틱)

//float4 VS( float4 pos : A ) : SV_POSITION
//{
//	return pos;
//}
//
//float4 PS() : SV_TARGET
//{
//	return float4(1.0f,0.7f,1.0f,1.0f); // RGBA
//}

// t : 쉐이더 리소스 뷰(SRV)용
// s : 샘플러스테이트용
// u : 무순차 엑세스 뷰(UAV)
// b : 상수버퍼뷰(CBV)
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

// 색칠용
// 1프레임당 호출횟수가 , 그림의 해상도만큼 호출
float4 PS(PixelInput input) : SV_TARGET
{
	/*float4 result = map.Sample(samp, input.uv);
	result.b = 0.5f;

	return result;*/

	return map.Sample(samp, input.uv);
}