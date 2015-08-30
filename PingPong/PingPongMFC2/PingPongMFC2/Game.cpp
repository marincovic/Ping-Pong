#include "stdafx.h"

#include"game.h"


GameMaster::GameMaster(){};

GameMaster::GameMaster(RECT Client) : m_ball(Ball(Client)), m_player1(Player(Client, 1)), m_player2(Player(Client, 2))
{
	m_WInfo = Client;
	m_ball.SetSpeed(),
	active = true;
}


CRect GameMaster::GetBallPosition()
{
	return m_ball.GetPosition();
}

CRect GameMaster::GetPaddle(int player_no)
{
	switch (player_no)
	{
	case 1:
		return m_player1.GetPaddle();
	case 2:
		return m_player2.GetPaddle();
	}
}


void GameMaster::BallSpeed()
{
	m_ball.SetSpeed();
}

void GameMaster::PlayerMove(int player, int up_down)
{
	switch (player)
	{
	case 1:
		switch (up_down)
		{
		case 1:
			m_player1.PaddleUp();
			break;
		case 2:
			m_player1.PaddleDown();
			break;
		}
		break;
	case 2:			
		switch (up_down)
		{
		case 1:
			m_player2.PaddleUp();
			break;
		case 2:
			m_player2.PaddleDown();
			break;
		}
		break;
	}
	CollisionCheck();
}



bool GameMaster::Status()
{
	if (active == true)
		active == false;
	else
		active == true;
	return active;
}

bool GameMaster::CollisionCheck()
{
	if (m_ball.GetPosition().TopLeft().x + 1 <= m_player1.GetPaddle().BottomRight().x &&
		m_ball.GetPosition().BottomRight().y + 1 >= m_player1.GetPaddle().TopLeft().y &&
		m_ball.GetPosition().TopLeft().y + 1 <= m_player1.GetPaddle().BottomRight().y)
		m_ball.ChangeSpeedX();

	if (m_ball.GetPosition().BottomRight().x + 1 >= m_player2.GetPaddle().TopLeft().x &&
		m_ball.GetPosition().BottomRight().y + 1 >= m_player2.GetPaddle().TopLeft().y &&
		m_ball.GetPosition().TopLeft().y + 1 <= m_player2.GetPaddle().BottomRight().y)
		m_ball.ChangeSpeedX();

	if (m_ball.GetPosition().TopLeft().y == m_WInfo.top || m_ball.GetPosition().BottomRight().y == m_WInfo.bottom)
		m_ball.ChangeSpeedY();

	if (m_ball.GetPosition().TopLeft().x <= m_player1.GetPaddle().BottomRight().x - 5)
	{
		return Score(2);
	}

	if (m_ball.GetPosition().BottomRight().x >= m_player2.GetPaddle().TopLeft().x + 5)
	{
		return Score(1);
	}

	return false;

}

bool GameMaster::Score(int player)
{
	switch (player)
	{
	case 1:
		m_player1.Score();
		break;
	case 2:
		m_player2.Score();
		break;
	}

	GameMaster::Status();

	GameMaster::m_ball.ResetBall(GameMaster::m_WInfo);

	return true;
}

bool GameMaster::BallMove()
{
	m_ball.BallMove();
	return CollisionCheck();
}