#include "stdafx.h"

#include"game.h"


GameMaster::GameMaster(){};

GameMaster::GameMaster(RECT Client) : m_ball(Ball(Client)), m_player1(Player(Client, 1)), m_player2(Player(Client, 2))
{
	m_WInfo = Client;
	active = true;
}

CRect GameMaster::GetBallPosition()
{
	return m_ball.GetPosition();
}

void GameMaster::Bump()
{
	m_ball.Bump();
}

void GameMaster::BallSpeed()
{
	m_ball.SetSpeed();
}

void GameMaster::BallMove()
{
	m_ball.BallMove();
	CollisionCheck();
}

void GameMaster::PlayerMove(int player, int up_down)
{
	switch (player)
	{
	case 1:
		switch (up_down)
		{
		case 1:
			m_player1.PaddleMoveX();
			break;
		case 2:
			m_player1.PaddleMoveY();
			break;
		}
		break;
	case 2:			
		switch (up_down)
		{
		case 1:
			m_player2.PaddleMoveX();
			break;
		case 2:
			m_player2.PaddleMoveY();
			break;
		}
		break;
	}
	CollisionCheck();
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

bool GameMaster::stauts()
{
	return active;
}

void GameMaster::CollisionCheck()
{
	if (m_ball.GetPosition().TopLeft().x == m_player1.GetPaddle().BottomRight().x)
		m_ball.ChangeSpeedX();
	if (m_ball.GetPosition().BottomRight().x == m_player2.GetPaddle().TopLeft().x)
		m_ball.ChangeSpeedX();
	if (m_ball.GetPosition().TopLeft().y == m_WInfo.top || m_ball.GetPosition().BottomRight().y == m_WInfo.bottom)
		m_ball.ChangeSpeedY();

}
