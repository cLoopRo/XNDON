#pragma once
#include "main.h"
#include "ResManager.h"
#include "XDObject.h"

class XDSprite : public XDObject
{


	
public :
	
	

	
	void updateAnimate(double dt)
	{
		dt_animation += dt;
		if ( list_animation.size() != 0 )
		{	
			if ( dt_animation >= 0.25 ){
				dt_animation -= 0.25;
				set_Image( (*list_animation.begin()) ); 
				list_animation.pop_front();
			}					
		}
		else
		{
			if ( dt_animation >= 0.25 ){
				dt_animation -= 0.25;
				set_Image( basic_animation_num );
				basic_animation_num = basic_animation_num/3;
			}
		}
	}

	void setAnimate(const list<int>& animation){
		list_animation.insert( list_animation.end(), animation.begin(), animation.end() );
	}

	double dt_animation;
	list<int> list_animation;
	list<int> basic_animation;
	int basic_animation_num;
	/*
	void draw(Graphics& G )
	{
		G.DrawImage( pImage, position.X - _width/2, position.Y - _height/2, 
			
			_width, _height, Gdiplus::UnitPixel);	
	}

	 pImage, position.X, position.Y, tilepos[curState][curPhase].leftup.X, tilepos[curState][curPhase].leftup.Y,
		width, height, Gdiplus::UnitPixel);

	void setNode(int _NodeNum)
	{
		

	}
	
*/


	virtual void drawSprite( Graphics& G );
	virtual void update(int dt);
	XDSprite();
	XDSprite(wstring _Path); 

	bool getDirection( ) {return direction;}
	void setDirection(bool _Direction) {direction = _Direction;}

	bool isControll( ) {return is_controll==1;}
	void setControll(bool _Controll) {is_controll = _Controll;}

	void updateState(int dt) {}  //I don't know what to do
	int getState( ) {return state;}

	void setHp(int _HP) {hp = _HP;}
	void addHP(int _HP) {hp += _HP;}
	void delHP(int _HP) {hp -= _HP;}
	int getHP( ) {return hp;}

	int getMaxHp( ) {return max_hp;}
	void setMaxHp(int _MaxHp) {max_hp = _MaxHp;}

	void setimg(wstring _Path);  //��θ� �޾� �ش� �̹����� ����� �ּҸ� �� Ŭ������ img�����Ϳ� �����Ų��.
	void draw(Graphics* memG);   //�׸��� �׸���. �̶� ���� ���۸��� �̿��ϹǷ� ����(�� ��Ʈ��)�� �޾Ƽ� �ű⿡ �׸��� �׸���.

	virtual ~XDSprite(void);

	void moveLeft(int dt) {position.X -= velocity.X*dt;}
	void moveRight(int dt) {position.X += velocity.X*dt;}
	void moveUp(int dt) {position.Z += velocity.Z*dt;}
	void moveDown(int dt) {position.Z -= velocity.Z*dt;}
	/* void move(int dt) {
		position.X += velocity.X*dt;
		position.Y += velocity.Y*dt;
		return;
	} */
	
	int getPositionX( ) {return position.X;}
	int getPositionY( ) {return position.Y;}
	int getPositionZ( ) {return position.Z;}
	int getVelocityX( ) {return velocity.X;}
	int getVelocityY( ) {return velocity.Y;}
	int getVelocityZ( ) {return velocity.Z;}
	void setPositionX(int _X) {position.X = _X;}
	void setPositionY(int _Y) {position.Y = _Y;}
	void setPositionZ(int _Z) {position.Z = _Z;}
	void setVelocityX(int _X) {velocity.X = _X;}
	void setVelocityY(int _Y) {velocity.Y = _Y;}
	void setVelocityZ(int _Z) {velocity.Z = _Z;}
	const Vector3& getPosition( ) {return position;}
	const Vector3& getVelocity( ) {return velocity;}
	void setPosition(const Vector3& _Position) {
		position.X = _Position.X;
		position.Y = _Position.Y;
		position.Z = _Position.Z;
	}
	void setVelocity(const Vector3& _Velocity) {
		velocity.X = _Velocity.X;
		velocity.Y = _Velocity.Y;
		velocity.Z = _Velocity.Z;
	}
	void setPosition(int _X, int _Y, int _Z) {position = Vector3(_X, _Y, _Z);}
	void setVelocity(int _X, int _Y, int _Z) {velocity = Vector3(_X, _Y, _Z);}


protected:
	static list<XDSprite> _sprites;


	//is_controll is 0 if it is already doing something
	//else 1
	int is_controll;

	bool _is_Controlled;

	bool direction;

	int max_hp;
	int hp;
	int state;

	Image* pImage;  //�̹���������
	Vector3 position; // Make Getter Setter
	Vector3 velocity; // Make Getter Setter

};
