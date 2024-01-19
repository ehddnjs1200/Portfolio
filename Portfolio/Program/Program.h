#pragma once
class Program
{
public:
	Program();
	~Program();

	void Update();
	void Render();

	//SRV GetImageInfoAtMousePosition() const {
	//	SRV imageInfo;
	//	

	//	return imageInfo;
	//}

private:
	shared_ptr<Scene> _scene;

};

