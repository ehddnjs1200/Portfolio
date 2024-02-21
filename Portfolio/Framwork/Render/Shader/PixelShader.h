#pragma once
class PixelShader : public Shader
{
public:
	PixelShader(wstring file);
	virtual ~PixelShader();

	virtual void CreateShader(wstring file) override;
	virtual void Set() override;

private:
	ComPtr<ID3D11PixelShader> _shader;
};

