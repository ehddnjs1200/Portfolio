// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <stack>
#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <random>
#include <string>
// 스마트포인터
// ComPtr
// get : 포인터 하나를 반환
// getaddressof : 더블 포인터를 반환
#include <wrl/client.h>
//#include <wrl>

#include <d3d11.h>
#include <d3dcompiler.h> // 쉐이더용. HLSL(Hight Level Shading Language)
#include <DirectXMath.h> // directX, GPU의 수학용


// 명지적인 라이브러리의 링크
#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d3dcompiler.lib")

// DirectXTex 라이브러리
#include "../DirectXTex/DirectXTex.h"


#include <d2d1_1.h>
#include <dwrite.h>

#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "dwrite.lib")

// ImGui
#include "../ImGUI/imgui.h"
#include "../ImGUI/imgui_impl_dx11.h"
#include "../ImGUI/imgui_impl_win32.h"

using namespace std;
using namespace DirectX; // DX에 관련된 데이터 타입을 사용하기 위해서
using namespace Microsoft::WRL;

// TpyeDefine
#include "TypeDefine.h"

// Device
#include "Framwork/Device/Device.h"



// Render

// Render - Buffer
#include "Framwork/Render/Buffer/ConstantBuffer.h"
#include "Framwork/Render/Buffer/GlobarBuffer.h"
#include "Framwork/Render/Buffer/IndexBuffer.h"
#include "Framwork/Render/Buffer/VertexBuffer.h"

// Render - Shader
#include "Framwork/Render/Shader/Shader.h"
#include "Framwork/Render/Shader/VertexShader.h"
#include "Framwork/Render/Shader/PixelShader.h"
#include "Framwork/Render/Shader/ShaderManager.h"

// Render - Texture
#include "Framwork/Render/Texture/SRV.h"
#include "Framwork/Render/Texture/TextureManager.h"

#include "Framwork/Render/VertexLayout.h"

// State
#include "Framwork/State/SamplerState.h"
#include "Framwork/State/BlendState.h"
#include "Framwork/State/StateManager.h"

// math
#include "Framwork/Math/Vector2.h"
#include "Framwork/Math/Transform.h"

// Collider
#include "Framwork/Collider/Collider.h"
#include "Framwork/Collider/CircleCollider.h"
#include "Framwork/Collider/RectCollider.h"
#include "Obejct/HealthBar/HealthBar.h"

// Utillity
#include "Framwork/Utillity/KeyBoard.h"
#include "Framwork/Utillity/Timer.h"
#include "Framwork/Utillity/Utillity.h"
#include "Framwork/Utillity/DXWrite.h"

// Action
#include "Framwork/Action/Action.h"

// Camera
#include "Framwork/Camera/Camera.h"

// Object

#include "Obejct/BagicObject/Quad.h"
#include "Obejct/BagicObject/Sprite.h"
#include "Obejct/BagicObject/Effect.h"
#include "Obejct/BagicObject/EffectManager.h"

#include "Obejct/HealthBar/HealthBar.h"

#include "Obejct/Card/Card.h"

// UI
#include "Obejct/UI/Button.h"

#include "Obejct/Character/Character.h"
#include "Obejct/Ironclad/Ironclad.h"
#include "Obejct/Monster/GremlinNob.h"

#include "Obejct/Map/Map1.h"

#include "Obejct/Card/AllCard.h"

#include "Framwork/UsingCard/UsingCard.h"
#include "Framwork/Bettle/Bettle.h"

// Scene
#include "Scene/Scene.h"
#include "Scene/SceneManager.h"

// Program
#include "Program/Program.h"