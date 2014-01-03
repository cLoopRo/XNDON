#pragma once
#include "main.h"
#include "Scene.h"

class Render
{
public:
	static void	setScene(Scene* _pScene);
	static void draw(HDC hdc);
	static void sceneUpdate(int dt);
	static Scene* getScene( ){	return pScene;	}
private:

	static Scene* pScene;
	static vector<Sprite*> sceneObject;
	static int dTime;
	Render(void);
	virtual ~Render(void);

};

