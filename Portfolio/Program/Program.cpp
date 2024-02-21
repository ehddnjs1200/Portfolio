#include "framework.h"
#include "Program.h"


Program::Program()
{
	srand(static_cast<unsigned int>(time(nullptr)));
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

	SceneManager::GetInstace()->Update();
}

void Program::Render()
{
	Device::GetInstance()->ClearColor();

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	Cam->SetViewPort();
	
	SceneManager::GetInstace()->Render();
	EffectManager::GetInstance()->Render();

	Cam->SetViewBuffer();
	Cam->SetProjectionBuffer();
		
	Cam->PostRender();
	SceneManager::GetInstace()->PostRender();

	ImGui::Text("FPS : %d", FPS);
	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	Device::GetInstance()->Present();
}
