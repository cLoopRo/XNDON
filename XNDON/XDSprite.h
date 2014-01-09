#pragma once
#include "main.h"
#include "ResManager.h"
#include "XDObject.h"

class XDSprite : public XDObject
{
private :
	bool isMoving; 	  
	bool isJumping;
	bool isSkilling;
	bool isBeingAttackted;
	
protected :
	/*<----- �ִϸ��̼� ���� ----->*/
	void setUpdate(double _DTIME)
	{
		dt_animation += _DTIME;
		if ( dt_animation = 0.25 )
		{
		
		
		}
	}




	// �ִϸ��̼� ���� ����
private:
	double dt_animation;

	queue< int , vector<int> > animation_queue; // ������ ��µ� �׸��� ��ȣ�� �����ϴ� ��
	vector< vector<int> > animation_list; // �ִϸ��̼ǵ��� �����ϴ� ��
	
	// �ִϸ��̼��� �߰��Ѵ�. ���� �ִϸ��̼��� ��ȣ�� ��ȯ�Ѵ�.
	int make_Animation(wstring _Img1, wstring _Img2, wstring _Img3 = _T(""), wstring _Img4 = _T(""))
	{
		vector<int> tmpList;
		tmpList.push_back( add_Image(_Img1) );
		tmpList.push_back( add_Image(_Img2) );
		if ( _Img3 != _T("") )
			tmpList.push_back( add_Image(_Img3) );
		if ( _Img4 != _T("") )
			tmpList.push_back( add_Image(_Img4) );
		animation_list.push_back( tmpList );
		return (animation_list.size()-1);
	}

	// ���� �ִϸ��̼��� ť�� �ִ´�.
	void set_animation(int _N)
	{
		for(int i=0; i<animation_list[_N].size(); i++)
		animation_queue.push(animation_list[_N][i] );
	}

	/*<---------------- �ִϸ��̼� ���� ���� ------->*/	
	
public:

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



/*
	<----- �̹��� ���� ���� ----->
�̹����� �⺻������ Gdiplus �� Image �� ���� �����Ѵ�.
�⺻������ �� ��ü�� �̹����� �����͸��� ������ ������

�̹����� �ߺ��� ��ο� �̸��� ���ؼ��� Ȯ���� �ϸ�
static map<wstring, Image* >  _images; => (RB TREE) �� ����Ͽ�
���� �̹������� �����Ѵ�.

�� ��ü�� �̹��������͸� ������ ���͸� �̿��Ͽ� �������� �̹����� �����Ѵ�.

P.S. ���� ��� �̹����� ũ��� �����̹Ƿ� ������� ������� �ʴ´�.
	<---------------------------> 
*/
private:
	Image* _pImage; // ���� ��������Ʈ�� �׸� �� ����ϴ� �̹���������
	vector< Image* > _pImages; // ���� ��������Ʈ�� ���õ� �̹������� ����Ű�� �����͵��� ����
	static map<wstring, Image* >  _images; // ��ü �̹������� �����ϴ� map

protected:
	/* 
	add_Image �Լ��� ��ο� �̸��� �̿��Ͽ� �̹����� �߰��ϸ�
	�ش� ��ü�� �߰��� �̹����� �����͸� ���Ϳ� �����Ͽ� ������ �Ǵµ�,
	�� ���� ���� �߰��� �̹����� �����Ͱ� ����� �ε����� ��ȯ�Ѵ�. 
	*/	
	int add_Image(wstring _Path){
		map<wstring, Image*>::iterator itr;
		// �߰��� ��ΰ� map �� �ִ����� Ȯ���ϰ�, pImage �߰��� �̹����� ����Ű���� �Ѵ�.
		if ( _images.end() == ( itr = _images.find(_Path) )  ) 
		{	// �������� �ʴ´ٸ� ���� �Ҵ��Ͽ� �߰��Ѵ�.
			Image* pImage = new Image(_Path.c_str());
			_images.insert ( std::pair<wstring, Image* >(_Path, _pImage) );
		}
		else
		{	// �����Ѵٸ� �װ��� �ּҸ� ��ȯ�Ѵ�.
			_pImage = itr->second;
		}
		// ���Ϳ� ���ο��̹����� ����Ű�� �����Ͱ� �ִ��� Ȯ���ϰ�, ������ �� �ε����� ��ȯ�Ѵ�.
		for(int i=0; i<_pImages.size(); i++){
			if ( pImage == _pImages[i] )
				return i;
		}
		// �׷��� ������ ���Ϳ� �̹��������͸� �߰��ϰ�, �ε����� ��ȯ�Ѵ�.
		_pImages.push_back( pImage );
		return (_pImages.size()-1); 
	}
	
	// set_Image �Լ��� pImage�� ���� ���Ϳ� ����� �̹��� �� �ش� ������ ���� ����Ű�����Ѵ�.
	void set_Image(int _N)
	{
		_pImage = _pImages[_N];	
	}
	// ���� pImage �� ����Ű�� �̹����� �׸���.
	void draw(Graphics& G)
	{
//		G.DrawImage( pImage, position.X - _width/2, position.Y - _height/2, _width, _height, Gdiplus::UnitPixel);	
	}




};
