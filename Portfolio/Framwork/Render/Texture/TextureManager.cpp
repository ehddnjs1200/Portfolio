#include "framework.h"
#include "TextureManager.h"

TextureManager* TextureManager::_instance = nullptr;

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
}

shared_ptr<SRV> TextureManager::Add(wstring file)
{
    if(_textureMapping.count(file) > 0)
        return _textureMapping[file];

    // map의 갯수가 0보다 작으면
    _textureMapping[file] = make_shared<SRV>(file);
    return _textureMapping[file];
}
