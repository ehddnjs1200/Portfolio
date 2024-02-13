#pragma once
class Map1
{
public:
	Map1();
	~Map1();

	void Update();
	void Render();

	void Init();
	void Setting();

private:
	shared_ptr<Quad> backgrund1;
	//shared_ptr<Quad> backgrund2;
};

