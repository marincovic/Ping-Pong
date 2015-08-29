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

	POINT GetPosition()
	{
		return m_ballPosition;
	}

	int GetBallSize()
	{
		return m_ballSize;
	}
};