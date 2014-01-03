#pragma once
#include "main.h"
#include "ResManager.h"

class GameObject
{
public:
	GameObject( );
	
	void setImage(const wstring& _Path);
	Image* getImage( );

	inline int getPositionX( ){	return posX;	}
	inline int getPositionY( ){	return posY;	}
	inline int getPositionZ( ){	return posZ;	}
		
	inline void moveRight( ){ posX += velocityX; }
	inline void moveLeft( ){ posX -= velocityX; } 
	inline void moveTop( ){ posZ += velocityZ;	}
	inline void moveBottom( ){	posZ -= velocityZ;}
	
	virtual ~GameObject(void);

private:
	Image *pImage;
	
	int posX;
	int posY;
	int posZ;

	int velocityX;
	int velocityZ;

};


