#pragma once
#include "main.h"
#include "ResManager.h"

class GameObject
{
public:
	GameObject(void);
	virtual ~GameObject(void);
	Image getImage();

	void setImage(WCHAR* _Path);
	int getPositionX(){	return pos.X;	}
	int getPositionY(){ return pos.Y;	}
	Point getPosition(){	return pos;	}

private:
	Image *pImage;
	Point pos;
public:

};


