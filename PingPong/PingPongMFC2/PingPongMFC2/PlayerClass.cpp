#include "stdafx.h"

class Player{
private:
	int m_playerNumber;
	POINT m_position;
	POINT m_size;

public:
	Player(){};
	Player(WINDOWINFO windinf, int player_no) : m_playerNumber(player_no)
	{
		if (m_playerNumber == 1)
		{
			m_position.x = windinf.rcClient.left + 10;
			m_position.y = windinf.rcClient.bottom / 2;
		}
		else
		{
			m_position.x = windinf.rcClient.right - 10;
			m_position.y = windinf.rcClient.bottom / 2;
		}
		m_size.y = 20;
		m_size.x = 10;
	}

	CRect GetPaddle()
	{
		POINT Bottom;
		Bottom.x = m_position.x + m_size.x;
		Bottom.y = m_position.y + m_size.y;
		return CRect(m_position, Bottom);

	}

	void PaddleMove()
	{
		m_position.x += 5;
	}
};