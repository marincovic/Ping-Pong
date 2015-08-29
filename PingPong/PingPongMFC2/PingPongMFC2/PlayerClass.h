#include "stdafx.h"

class Player{
private:
	int m_playerNumber;
	POINT m_position;
	POINT m_size;

public:
	Player();

	Player(RECT Client, int player_no);

	CRect GetPaddle();

	void PaddleMoveX();

	void PaddleMoveY();


	CRect Bump();

};