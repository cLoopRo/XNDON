#pragma once
#include "Sprite.h"
#include <vector>

class Gob : public Sprite
{

public :

	Gob();
	
	//constructor inherit - �����ڴ� ���߿� �ʿ��� �͸� �����ϰ� Parent Constructor�� ���� �����ϸ� �ǹǷ� ���� ������ ����

	enum STATE_LIST {DEAF, WALK, ATT_ON, ATT_ED, DEAD}; //���¸�� {����Ʈ/�ȱ�/����/�ǰ�/����}
	vector<int>End_phase;//����� ����

	int getState();
	void setState(int _state);

	int getPhase();
	void getPhase(int _phase);

//	virtual ~Gob();


private :

	int curState;
	int curPhase;

};
