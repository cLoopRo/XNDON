#pragma once
#include "sprite.h"
#include "main.h"

class Player : public Sprite
{
public :
	enum STATE_LIST {STND, MOV, GUARD, KICK, SHIELD_ATTCK}; //���� ���
	map<int,int>END_STATE; //���� �� ������ ��
	map<int,int>BACK_STATE; //���� �� ���� �� ���ԵǴ� ���� [ex, ����ġ�� ���� ���л��� ����]
	Player( ); // update ��� �Ҷ����� �׸��� ������ ������ ���� ��. �˾Ƽ� ������ ������ ȣ�� �ؾ� �� 
	Player(wstring _Path);	
	int getState();
	
	void drawPlayer(Graphics& G);
//	int setState(int);
	
	int getPhase();
//	int setPhase(int);

	void update();
	virtual ~Player(void);

private :
	int curState;
	int curPhase;
};
