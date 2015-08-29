#include "stdafx.h"

#include"BallClass.cpp"
#include"PlayerClass.cpp"

class GameMaster
{
private:
	Ball m_ball;
	Player m_player1, m_player2;
	bool active = false;
	 
public:
	GameMaster(){};
	GameMaster(WINDOWINFO WInfo) : m_ball(Ball(WInfo)), m_player1(Player(WInfo, 1)), m_player2(Player(WInfo, 2))
	{
		active = true;
	}

	CRect GetBallPosition()
	{
		return m_ball.GetPosition();
	}

	void BallMove()
	{
		m_ball.BallMove();
	}
	void PlayerMove(int player)
	{
		switch (player)
		{
		case 1:
			break;
		case 2:
			break;
		}
	}

	CRect GetPaddle(int player_no)
	{
		switch (player_no)
		{
		case 1:
			return m_player1.GetPaddle();
		case 2:
			return m_player2.GetPaddle();
		}
	}
	bool stauts()
	{
		return active;
	}

};