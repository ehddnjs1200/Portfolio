#include "framework.h"
#include "Program.h"

#include "Scene/CameraScene.h"

Program::Program()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	_scene = make_shared<CameraScene>();
}

Program::~Program()
{
}

void Program::Update()
{
	KeyBoard::GetInstance()->Update();
	Timer::GetInstance()->Update();
	Camera::GetInstance()->Update();
	EffectManager::GetInstance()->Update();

	_scene->Update();
}

void Program::Render()
{
	Device::GetInstance()->ClearColor();

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	Cam->SetViewPort();
	
	_scene->Render();
	EffectManager::GetInstance()->Render();

	Cam->SetViewBuffer();
	Cam->SetProjectionBuffer();
		
	Cam->PostRender();
	_scene->PostRender();

	ImGui::Text("FPS : %d", FPS);

	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	Device::GetInstance()->Present();
}
