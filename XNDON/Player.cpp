#include "Player.h"

Player::~Player(void)
{

}

void Player::update()
{
	/*
		���� ó���� �� ��
	*/

	//���� ó���� �� �ϰ���, ���� ������� ����
	if(END_STATE[curState]!=curPhase)
	{
		++curPhase;
	}
	else
	{
		setPhase(1);
	//	setState(BACK_STATE[curState]);
	}
}

//�÷��̾� ���� ���� ��ȯ
int Player::getState()
{
	return curState;
}

//���� ������ ��ȯ
int Player::getPhase()
{
	return curPhase;
}

//�÷��̾� ���� ���� ����, �� ������ 0�� ������� ��
void Player::setState(int nwState)
{
	curState = nwState;
	setPhase(1);
}

void Player::setPhase(int p)
{
	curPhase = p;
}

Player::Player(void)
{
	setState(STND);
	setPhase(1);
	END_STATE[STND] = 1;
	END_STATE[MOV] = 3;
	END_STATE[GUARD] = 1;
	END_STATE[SHIELD_ATTCK] = 1;
	END_STATE[KICK] = 2;

//	BACK_STATE[STND] = STND;
//	BACK_STATE[MOV] = MOV;
//	BACK_STATE[GUARD] = GUARD;
//	BACK_STATE[SHIELD_ATTCK] = GUARD;
//	BACK_STATE[KICK] = STND;
}