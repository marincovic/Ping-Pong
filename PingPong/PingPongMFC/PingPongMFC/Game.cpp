#include "stdafx.h"

#include"BallClass.cpp"
#include"PlayerClass.cpp"

class GameMaster
{
private:
	Ball m_ball;
	Player m_player1, m_player2;
	 
public:
	GameMaster(){};
	GameMaster(WINDOWINFO WInfo) : m_ball(Ball(WInfo)), m_player1(Player(WInfo, 1)), m_player2(Player(WInfo, 2))
	{
		
	}

	Ball GetBall()
	{
		return m_ball;
	}

};