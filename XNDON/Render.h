#pragma once
#include "main.h"
#include "XDScene.h"



class Render
{
public:
	static void	setScene(XDScene* _pScene);
	static void draw(HDC hdc);
	static void sceneUpdate(int dt);
	static void sceneUpdate();
	static XDScene* getScene( ){	return pScene;	}

private:
	static CachedBitmap *pCBit;
	static XDScene* pScene;
	static vector<XDSprite*> sceneObject;
	static int dTime;
	Render(void);
	virtual ~Render(void);

};

