#include "stdafx.h"

class Player{
private:
	int m_playerNumber;
	POINT m_position;
	int m_size;

public:
	Player(){};
	Player(WINDOWINFO windinf, int player_no) : m_playerNumber(player_no)
	{
		if (m_playerNumber == 1)
		{
			m_position.x = windinf.rcClient.left;
			m_position.y = windinf.rcClient.bottom / 2;
		}
		else
		{
			m_position.x = windinf.rcClient.right;
			m_position.y = windinf.rcClient.bottom / 2;
		}

	}
};