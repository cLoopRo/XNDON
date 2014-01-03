#pragma once

#include "main.h"
#include "Scene.h"
#include "Sprite.h"

class Render
{
public:
	static void	set_Scene(Scene* _pScene);
	static void draw(HDC hdc);
	static void sceneUpdate( );

private:

	static Scene* pScene;
	static vector<Sprite> sceneObject;
	
	Render(void);
	virtual ~Render(void);

};

