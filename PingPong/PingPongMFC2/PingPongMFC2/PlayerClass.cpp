#include "stdafx.h"

#include "PlayerClass.h"

Player::Player(){};

Player::Player(RECT Client, int player_no) : m_playerNumber(player_no)
	{
		m_points = 0;
		m_Client = Client;


		SetSize(Client);

		
		SetPaddle(Client, player_no);
	}


CRect Player::GetPaddle()
	{
		POINT Bottom;
		Bottom.x = m_position.x + m_size.x;
		Bottom.y = m_position.y + m_size.y;
		return CRect(m_position, Bottom);

	}



void Player::PaddleUp()
	{
	if (m_position.y <= m_Client.TopLeft().y)
		return;
		m_position.y -= 5;
	}
void Player::PaddleDown()
	{
	if (m_position.y + m_size.y >= m_Client.BottomRight().y)
		return;
		m_position.y += 5;
	}
void Player::Score()
{
	++m_points;
}
void Player::SetPaddle(CRect NewPosition, int Player)
{
	if (m_playerNumber == 1)
	{
		m_position.x = NewPosition.left + 10;
		m_position.y = NewPosition.bottom / 2;
	}
	else
	{
		m_position.x = NewPosition.right - 10 - m_size.x;
		m_position.y = NewPosition.bottom / 2;
	}
}
void Player::SetSize(CRect client)
{
	m_size.x = client.Width() / 150;
	m_size.y = client.Height() / 7;
}
void Player::SetClient(CRect client)
{
	m_Client = client;
}

int Player::GetScore()
{
	return m_points;
}