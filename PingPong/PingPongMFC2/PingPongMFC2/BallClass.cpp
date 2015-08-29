#include "stdafx.h"
#include"BallClass.h"

Ball::Ball(){};
Ball::Ball(RECT Client)
{
	m_ballPosition.x = Client.right / 2;
	m_ballPosition.y = Client.bottom / 2;

	m_ballSize = (Client.bottom - Client.top) / 50;
	if (m_ballSize < 3)
		m_ballSize = 3;

	m_speed.x = 0;
	m_speed.y = 0;
}

CRect Ball::GetPosition()
{
	POINT Bottom;
	Bottom.x = m_ballPosition.x + m_ballSize;
	Bottom.y = m_ballPosition.y + m_ballSize;
	return CRect(m_ballPosition,Bottom);
}

int Ball::GetBallSize()
{
	return m_ballSize;
}

void Ball::SetSpeed()
{
	m_speed.x = 3;
	m_speed.y = 3;
}

void Ball::ChangeSpeedX()
{
	m_speed.x *= -1;
}
	
void Ball::ChangeSpeedY()
{
	m_speed.y *= -1;
}

void Ball::BallMove()
{
	m_ballPosition.x += m_speed.x;
	m_ballPosition.y += m_speed.y;
}

void Ball::Bump()
{
	m_speed.x *= 2;
	m_speed.y *= 2;
}
