#pragma once

#define WIN_STARTX 0
#define WIN_STARTY 0
#define WIN_WIDTH 1280
#define WIN_HEIGHT 720
#define CenterX WIN_WIDTH * 0.5f
#define CenterY WIN_HEIGHT * 0.5f

#define PI 3.141592

#define LERP(start, end, t) start + (end - start) * t

#define Float2 XMFLOAT2

extern HWND hWnd;

class Vector2;
extern Vector2 mousepos;
typedef function<void()> CallBack; // void형식으로 받겠다.
typedef function<void(int a)> CallBackParam; // void형식으로 int형인 a를 매게변수로 받겠다.
typedef function<int(int)> CallBackint; // int형식으로 int형인 매게변수로 받겠다.


class Device;
#define DEVICE Device::GetInstance()->GetDevice()
#define DEVICE_CONTEXT Device::GetInstance()->GetDeviceContext()

class StateManager;
#define SAMPLER StateManager::GetInstance()->GetSampler()
#define AlphaBlendState StateManager::GetInstance()->GetAlphaBlend()
#define AdditiveBlendState StateManager::GetInstance()->GetAdditiveBlend()

class TextureManager;
#define TextureAdd(file) TextureManager::GetInstance()->Add(file);

class KeyBoard;
#define KeyDown(k)	KeyBoard::GetInstance()->KEYDOWN(k)
#define KeyUp(k)	KeyBoard::GetInstance()->KEYUP(k)
#define KeyPress(k)	KeyBoard::GetInstance()->KEYPRESS(k)

class Timer;
#define DELTATIME Timer::GetInstance()->GetElasedTime()
#define FPS Timer::GetInstance()->GetFPS()

class Camera;
#define Cam Camera::GetInstance()

// color
static XMFLOAT4 RED		= XMFLOAT4(255.0f, 0.0f  , 0.0f  , 1.0f);
static XMFLOAT4 GREEN	= XMFLOAT4(0.0f  , 255.0f, 0.0f  , 1.0f);
static XMFLOAT4 BLUE	= XMFLOAT4(0.0f  , 0.0f  , 255.0f, 1.0f);