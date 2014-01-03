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

	// setState(); <- 애니메이션이나ㅣ 지금 상태랑 관련이 있는거야;
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


