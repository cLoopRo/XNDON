#include "Player.h"

Player::Player(void)
{
	setState(Player.STND);
	setPhase(1);
	END_STATE[Player.STND] = 1;
	END_STATE[Player.MOV] = 3;
	END_STATE[Player.GUARD] = 1;
	END_STATE[Player.SHIELD_ATTCK] = 1;
	END_STATE[Player.KICK] = 2;

	BACK_STATE[Player.STND] = Player.STND;
	BACK_STATE[Player.MOV] = Player.MOV;
	BACK_STATE[Player.GUARD] = Player.GUARD;
	BACK_STATE[Player.SHIELD_ATTCK] = Player.GUARD;
	BACK_STATE[Player.KICK] = Player.STND;
}

Player::~Player(void)
{

}

void Player::update()
{
	/*
		뭔가 처리가 잘 됨
	*/

	//뭔가 처리를 잘 하고나서, 다음 페이즈로 변경
	if(END_STATE[curState]!=curPhase)
	{
		++curPhase;
	}
	else
	{
		setPhase(1);
		setState(BACK_STATE[curState]);
	}
}

//플레이어 현재 상태 반환
int Player::getState()
{
	return curState;
}

//현재 페이즈 반환
int Player::getPhase()
{
	return curPhase;
}

//플레이어 현재 상태 변경, 그 상태의 0번 페이즈로 감
int Player::setState(int nwState)
{
	curState = nwState;
	setPhase(1);
}

int Player::setPhase(int p)
{
	curPhase = p;
}
