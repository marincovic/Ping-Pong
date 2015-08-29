#include "stdafx.h"

class Ball
{
private:
	POINT m_speed;
	POINT m_ballPosition;
	int m_ballSize;
	

public:
	Ball(){};
	Ball(WINDOWINFO windinf)
	{
		m_ballPosition.x = windinf.rcClient.right / 2;
		m_ballPosition.y = windinf.rcClient.bottom / 2;

		m_ballSize = (windinf.rcClient.bottom-windinf.rcClient.top) / 50;
		if (m_ballSize < 3)
			m_ballSize = 3;

		m_speed.x = 0;
		m_speed.y = 0;
	}

	CRect GetPosition()
	{
		POINT Bottom;
		Bottom.x = m_ballPosition.x + m_ballSize;
		Bottom.y = m_ballPosition.y + m_ballSize;
		return CRect(m_ballPosition,Bottom);
	}

	int GetBallSize()
	{
		return m_ballSize;
	}

	void SetSpeed()
	{
		m_speed.x = 3;
		m_speed.y = 3;
	}

	void BallMove()
	{
		m_ballPosition.x += m_speed.x;
		m_ballPosition.y += m_speed.y;
	}
};