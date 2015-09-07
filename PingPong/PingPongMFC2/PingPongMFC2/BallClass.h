#include "stdafx.h"

class Ball
{
private:

	POINT m_speed;
	POINT m_ballPosition;

	int m_ballSize;

	CRect m_Winfo;

public:
	Ball();
	Ball(RECT Client);

	CRect GetPosition();

	int GetBallSize();

	void SetClient(CRect client);
	void ResetBall(RECT Client);
	void SetSpeed();
	void ChangeSpeedX();
	void ChangeSpeedY();
	void BallMove();
	void SetSize(CRect client);
	void SetPosition(CRect position);
};