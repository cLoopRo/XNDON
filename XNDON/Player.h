#pragma once
#include "InputController.h"
#include "sprite.h"
#include "main.h"

class Player : public Sprite
{
public :
	enum STATE_LIST {STND, MOV, GUARD, KICK, SHIELD_ATTCK}; //���� ���
	map<int,int>END_STATE; //���� �� ������ ��

	//map<int,int>BACK_STATE; //���� �� ���� �� ���ԵǴ� ���� [ex, ����ġ�� ���� ���л��� ����]
	Player( ); // update ��� �Ҷ����� �׸��� ������ ������ ���� ��. �˾Ƽ� ������ ������ ȣ�� �ؾ� �� 
	
	// �÷��̾��� ���� ������ �Լ��� ��Ÿ����.
	virtual void update(int dt);// �÷��̾� ���¸� ������Ʈ �ϴ� �Լ�
	
	void Player :: drawSprite( Graphics& G );

	int getState();
	void setState(int);
	
	int getPhase();
	void setPhase(int);

//	void update();
	virtual ~Player(void);

private :
	int curState;
	int curPhase;
};
