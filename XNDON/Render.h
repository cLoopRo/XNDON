#pragma once

#include "main.h"
#include "Scene.h"
#include "Sprite.h"



class Render
{
public:
	static void	set_Scene(Scene* _pScene);
	static void draw(HDC hdc);
	static void sceneUpdate(int dt);
	static void sceneUpdate();
	static bool keys[256];

private:
	static CachedBitmap *pCBit;
	static Scene* pScene;
	static vector<Sprite*> sceneObject;
	static int dTime;
	Render(void);
	virtual ~Render(void);

};

