#include "stdafx.h"

#include"BallClass.h"
#include"PlayerClass.h"

class GameMaster
{
private:
	Ball m_ball;
	Player m_player1, m_player2;
	bool active = false;
	RECT m_WInfo;

public:
	GameMaster();

	GameMaster(RECT Client);

	CRect GetBallPosition();

	void Bump();

	void BallSpeed();

	void BallMove();

	void PlayerMove(int player, int up_down);

	CRect GetPaddle(int player_no);

	bool stauts();

	void CollisionCheck();

};