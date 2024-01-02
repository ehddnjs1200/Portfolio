// t : 쉐이더 리소스 부(SRV)
// s : 샘플러스테이
// u : 무순차 엑세스 뷰(UAV)
// b : 상수버퍼(CBV)

cbuffer World : register(b0)
{
	matrix world;
}

cbuffer View : register(b1)
{
	matrix view;
}

cbuffer Projection : register(b2)
{
	matrix projection;
}

struct VertexInput
{
	float4 pos : POSITION;
};

struct VertexOutput
{
	float4 pos : SV_POSITION;
};

VertexOutput VS(VertexInput input)
{
	VertexOutput output;
	// 1
	output.pos = mul(input.pos, world);
	output.pos = mul(output.pos, view);
	output.pos = mul(output.pos, projection);

	// 2
	//matrix wvp = mul(world, view);
	//wvp = mul(wvp, projection);
	//output.pos = mul(input.pos. wvp);

	return output;
}