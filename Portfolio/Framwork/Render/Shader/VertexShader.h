#pragma once
class VertexShader : public Shader
{
public:
	VertexShader(wstring file);
	virtual ~VertexShader();

	virtual void CreateShader(wstring file) override;
	virtual void Set() override;

private:
	ComPtr<ID3D11VertexShader> _shader;
	ComPtr<ID3D11InputLayout> _inputLayout;
};

