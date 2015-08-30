#include "stdafx.h"

#include "PlayerClass.h"

Player::Player(){};

Player::Player(RECT Client, int player_no) : m_playerNumber(player_no)
	{
		m_points = 0;
		m_size.y = 75;
		m_size.x = 15;

		m_Client = Client;

		if (m_playerNumber == 1)
		{
			m_position.x = Client.left + 10;
			m_position.y = Client.bottom / 2;
		}
		else
		{
			m_position.x = Client.right - 10 - m_size.x;
			m_position.y = Client.bottom / 2;
		}

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

void Player::SetPaddle(POINT NewPosition)
{
	m_position = NewPosition;
}

