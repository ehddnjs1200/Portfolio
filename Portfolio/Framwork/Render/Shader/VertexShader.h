#pragma once
class VertexShader
{
public:
	VertexShader(wstring file);
	~VertexShader();

	void CreateShader(wstring file);
	void Set();

private:
	ComPtr<ID3D11VertexShader> _shader;
	ComPtr<ID3DBlob> _blob;
	ComPtr<ID3D11InputLayout> _inputLayout;
};

