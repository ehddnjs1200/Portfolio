#pragma once

class Vector2;

class SRV
{
public:
	SRV(wstring file);
	~SRV();

	void CreateImage(wstring file);
	void Set(int slot);

	Vector2 GetSize();


private:
	ComPtr<ID3D11ShaderResourceView> _srv;
	ScratchImage _image;
};

