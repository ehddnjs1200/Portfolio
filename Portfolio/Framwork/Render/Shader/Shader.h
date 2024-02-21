#pragma once
class Shader
{
public:
	Shader() {}
	virtual ~Shader() {}

	virtual void CreateShader(wstring file) abstract;
	virtual void Set() abstract;

protected:
	ComPtr<ID3DBlob> _blob;
};

