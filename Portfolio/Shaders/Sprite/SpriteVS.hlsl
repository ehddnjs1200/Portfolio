// t : ���̴� ���ҽ� ��(SRV)
// s : ���÷�������
// u : ������ ������ ��(UAV)
// b : �������(CBV)

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
	float2 uv : UV;
};

struct VertexOutput
{
	float4 pos : SV_POSITION;
	float2 uv : UV;
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

	output.uv = input.uv;

	return output;
}