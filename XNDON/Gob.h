#pragma once
#include "Sprite.h"
#include <vector>

class Gob : public Sprite
{

public :

	Gob();
	
	//constructor inherit - 생성자는 나중에 필요한 것만 설정하고 Parent Constructor를 통해 정의하면 되므로 현재 사정상 생략

	enum STATE_LIST {DEAF, WALK, ATT_ON, ATT_ED, DEAD}; //상태목록 {디폴트/걷기/공격/피격/죽음}
	vector<int>End_phase;//페이즈를 저장

	int getState();
	void setState(int _state);

	int getPhase();
	void getPhase(int _phase);

//	virtual ~Gob();


private :

	int curState;
	int curPhase;

};
