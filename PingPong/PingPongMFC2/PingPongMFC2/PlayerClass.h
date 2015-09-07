#include "stdafx.h"

class Player{
private:
	int m_playerNumber;
	int m_points;

	POINT m_position;
	POINT m_size;

	CRect m_Client;

public:
	Player();

	Player(RECT Client, int player_no);


	CRect GetPaddle();
	
	void SetClient(CRect client);
	void SetPaddle(CRect NewPosition, int player);
	void PaddleUp();
	void PaddleDown();
	void Score();
	void PaddleBump();
	void SetSize(CRect client);
};