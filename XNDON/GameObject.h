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
	// 

	// setState(); <- �ִϸ��̼��̳��� ���� ���¶� ������ �ִ°ž�;
	// 

	// moveRight();
	// moveLeft( );  /
	// setPosition( );
	// setVelocity(const Point& Pos);
	// setVelocity(int X, int Y);
	// setVelocityX(int X);
	// getPosition();
	// getPositionX();
	

private:
	Image *pImage;
	Point pos;
	int velocityX;
	int velocityY;


public:

};


