#include "stdafx.h"
#include"BallClass.h"

Ball::Ball(){};
Ball::Ball(RECT Client)
{
	m_ballPosition.x = Client.right / 2;
	m_ballPosition.y = Client.bottom / 2;

	m_Winfo = Client;

	Ball::SetSize(Client);
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
	srand(time(NULL));
	if (rand > 0)
	{
		m_speed.x = -1;
		m_speed.y = 1;
	}
	else
	{
		m_speed.x = 1;
		m_speed.y = -1;
	}
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
void Ball::ResetBall(RECT Client)
{
	m_ballPosition.x = Client.right / 2;
	m_ballPosition.y = Client.bottom / 2;
}
void Ball::SetSize(CRect client){
	m_ballSize = (client.bottom - client.top) / 40;
	if (m_ballSize < 3)
		m_ballSize = 3;
}
void Ball::SetClient(CRect client)
{
	m_Winfo = client;
}
void Ball::SetPosition(CRect position)
{
	m_ballPosition.x = position.Width() / 2;
	m_ballPosition.y = position.Height() / 2;
}