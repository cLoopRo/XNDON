#pragma once
#include "InputController.h"
#include "XDSprite.h"
#include "main.h"

#include <cmath>
#define PI 3.14159

typedef struct  
{
	Point leftup;
}TILEPOS;


class Player : public XDSprite
{
public :
	enum STATE_LIST {STND, MOV, GUARD, KICK, SHIELD_ATTCK}; //상태 목록
	map<int,int>NUM_PHASE; //상태 당 페이즈 수
	TILEPOS tilepos[5][5]; //타일셋

	//map<int,int>BACK_STATE; //상태 당 끝난 후 가게되는 상태 [ex, 방패치기 이후 방패상태 유지]
	Player( ); // update 출력 할때마다 그림이 움직일 것으로 생각 됨. 알아서 적당히 느리게 호출 해야 됨 
	
	// 플레이어의 동작 실행을 함수로 나타낸다.
	virtual void update(int dt);// 플레이어 상태를 업데이트 하는 함수
	
	void Player :: drawSprite( Graphics& G );

	int getState();
	void setState(int);
	
	int getPhase();
	void setPhase(int);

//	void update();
	virtual ~Player(void);

private :
	bool flip;
	int curState;
	int curPhase;

	int dTimeMove;
};
