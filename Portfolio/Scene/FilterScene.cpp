#include "framework.h"
#include "FilterScene.h"

FilterScene::FilterScene()
{
	_background = make_shared<Quad>(L"BlueExplosion.png", L"FIlterPS");
	_background->GetTransForm()->GetPos() = Vector2(CenterX, CenterY);

	_fileterBuffer = make_shared<FilterBuffer>();
	_fileterBuffer->_data.LR = 0; // 왼오른
	_fileterBuffer->_data.TB = 0; // 위아래
}

FilterScene::~FilterScene()
{
}

void FilterScene::Update()
{
	_fileterBuffer->SetPsBuffer(0);
	_background->Update();

}


void FilterScene::Render()
{
	_background->Render();
}

void FilterScene::PostRender()
{
	ImGui::SliderInt("left right", &_fileterBuffer->_data.LR, 0 , 1);
	ImGui::SliderInt("top bottom", &_fileterBuffer->_data.TB, 0 , 1);
}
