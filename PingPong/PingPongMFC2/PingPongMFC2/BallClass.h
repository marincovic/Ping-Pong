#include "stdafx.h"

class Ball
{
private:

	POINT m_speed;
	POINT m_ballPosition;
	int m_ballSize;

public:
	Ball();

	Ball(RECT Client);

	CRect GetPosition();

	int GetBallSize();

	void SetSpeed();

	void ChangeSpeedX();

	void ChangeSpeedY();

	void BallMove();

	void Bump();
};