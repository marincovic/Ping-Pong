#include "stdafx.h"

#include "PlayerClass.h"

Player::Player(){};
Player::Player(RECT Client, int player_no) : m_playerNumber(player_no)
	{
		if (m_playerNumber == 1)
		{
			m_position.x = Client.left + 10;
			m_position.y = Client.bottom / 2;
		}
		else
		{
			m_position.x = Client.right - 10;
			m_position.y = Client.bottom / 2;
		}
		m_size.y = 20;
		m_size.x = 10;
	}

CRect Player::GetPaddle()
	{
		POINT Bottom;
		Bottom.x = m_position.x + m_size.x;
		Bottom.y = m_position.y + m_size.y;
		return CRect(m_position, Bottom);

	}

void Player::PaddleMoveX()
	{
		m_position.x += 5;
	}

void Player::PaddleMoveY()
	{
		m_position.y += 5;
	}
	
CRect Player::Bump()
	{
		POINT Bottom;
		Bottom.x = m_position.x + m_size.x + 5;
		Bottom.y = m_position.y + m_size.y + 5;
		return CRect(m_position, Bottom);
	}
