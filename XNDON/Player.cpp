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
		setState(BACK_STATE[curState]);
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
int Player::setState(int nwState)
{
	curState = nwState;
	setPhase(1);
}

int Player::setPhase(int p)
{
	curPhase = p;
}
