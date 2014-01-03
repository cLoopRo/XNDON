#pragma once
#include "sprite.h"
#include <map>

class Player : public Sprite
{
public :
	enum STATE_LIST {STND, MOV, GUARD, KICK, SHIELD_ATTCK}; //���� ���
	map<int,int>END_STATE; //���� �� ������ ��
	map<int,int>BACK_STATE; //���� �� ���� �� ���ԵǴ� ���� [ex, ����ġ�� ���� ���л��� ����]
	Player(void); // update ��� �Ҷ����� �׸��� ������ ������ ���� ��. �˾Ƽ� ������ ������ ȣ�� �ؾ� �� 
	
	// �÷��̾��� ���� ������ �Լ��� ��Ÿ����.
	virtual void update();// �÷��̾� ���¸� ������Ʈ �ϴ� �Լ�
	
	int getState();
	void setState(int);
	
	int getPhase();
	void setPhase(int);

	virtual ~Player(void);

private :
	int curState;
	int curPhase;
};