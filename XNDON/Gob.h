#pragma once
#include "sprite.h"
#include<cmath>

class Gob :
	public Sprite
{
public:
	Gob(void);
	Gob(const Vector3&);
	void update(int dt);
	void drawSprite(Graphics& G);
	virtual ~Gob(void);
	void lookat(Vector3);
	void setplpos(const Vector3&);

private:
	Vector3 plpos;
};

