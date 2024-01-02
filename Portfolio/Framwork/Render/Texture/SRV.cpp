#include "framework.h"
#include "SRV.h"

SRV::SRV(wstring file)
{
    CreateImage(file);
}

SRV::~SRV()
{
}

void SRV::CreateImage(wstring file)
{
    wstring filename = L"Resource/" + file;
    LoadFromWICFile(filename.data(), WIC_FLAGS_NONE, nullptr, _image);
    CreateShaderResourceView(DEVICE.Get(), _image.GetImages(), _image.GetImageCount(),
        _image.GetMetadata(), _srv.GetAddressOf());
}

void SRV::Set(int slot)
{
    DEVICE_CONTEXT->PSSetShaderResources(slot, 1, _srv.GetAddressOf());
}

Vector2 SRV::GetSize()
{
    return Vector2(_image.GetMetadata().width, _image.GetMetadata().height);
}
