#include "Player.h"

void Player :: drawPlayer( Graphics& G )
{
	int width = 180;
	int height = 240;
	if(flip) pImage->RotateFlip(Gdiplus::Rotate180FlipY);
	G.DrawImage( pImage, position.X, position.Y, tilepos[curState][curPhase].leftup.X, tilepos[curState][curPhase].leftup.Y,
		width, height, Gdiplus::UnitPixel); 
	if(flip) pImage->RotateFlip(Gdiplus::Rotate180FlipY);
}


Player::Player( )
	: Sprite( L"./ShieldMan.png" )
{

	setState(STND);
	setPhase(1);

	NUM_PHASE[STND] = 1;
	NUM_PHASE[MOV] = 4;
	NUM_PHASE[GUARD] = 1;
	NUM_PHASE[SHIELD_ATTCK] = 1;
	NUM_PHASE[KICK] = 2;

	//스탠드
	tilepos[STND][1].leftup.X = 0;
	tilepos[STND][1].leftup.Y = 0;

	//무브
	tilepos[MOV][1].leftup.X = 0;
	tilepos[MOV][1].leftup.Y = 0;

	tilepos[MOV][2].leftup.X = 180;
	tilepos[MOV][2].leftup.Y = 0;

	tilepos[MOV][3].leftup.X = 0;
	tilepos[MOV][3].leftup.Y = 0;

	tilepos[MOV][4].leftup.X = 360;
	tilepos[MOV][4].leftup.Y = 0;

	//
	for(int i = GUARD;i != SHIELD_ATTCK; ++i)
	{
		for(int j = 0; j <= NUM_PHASE[i];++j)
		{
			tilepos[i][j].leftup.X = (j-1)*180;
			tilepos[i][j].leftup.Y = (i-1)*240;
		}
	}
/*	setState(Player.STND);
	setPhase(1);
	NUM_PHASE[Player.STND] = 1;
	NUM_PHASE[Player.MOV] = 3;
	NUM_PHASE[Player.GUARD] = 1;
	NUM_PHASE[Player.SHIELD_ATTCK] = 1;
	NUM_PHASE[Player.KICK] = 2;

	BACK_STATE[Player::STND] = Player.STND;
	BACK_STATE[Player::MOV] = Player.MOV;
	BACK_STATE[Player::GUARD] = Player.GUARD;
	BACK_STATE[Player::SHIELD_ATTCK] = Player.GUARD;
	BACK_STATE[Player::KICK] = Player.STND;
	*/
}


Player::~Player(void)
{

}

void Player::update(int dt)
{
	if ( InputController::keys[37]  ) // left
	{
		moveLeft(dt);
		flip = true;
		setState(MOV);
	}
	else if ( InputController::keys[38]  ) // up
	{
		moveUp(dt);
		setState(MOV);
	}
	else if ( InputController::keys[39] ) // right
	{
		moveRight(dt);
		flip = false;
		setState(MOV);
	}
	else if ( InputController::keys[40] ) // down
	{
		moveDown(dt);
		setState(MOV);
	}
	else
	{
		setState(STND);
	}

	//뭔가 처리를 잘 하고나서, 다음 페이즈로 변경
	if(curPhase < NUM_PHASE[curState])
	{
		setPhase(curPhase+1);
	}
	else
	{
		setPhase(1);
	//	setState(BACK_STATE[curState]);
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
void Player::setState(int nwState)
{
	curState = nwState;
}

void Player::setPhase(int p)
{
	curPhase = p;
}
