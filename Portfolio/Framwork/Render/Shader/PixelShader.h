#pragma once
class PixelShader
{
public:
	PixelShader(wstring file);
	~PixelShader();

	void CreateShader(wstring file);
	void Set();

private:
	ComPtr<ID3D11PixelShader> _shader;
	ComPtr<ID3DBlob> _blob;
};

