#include "stdafx.h"

#include"BallClass.h"
#include"PlayerClass.h"

class GameMaster
{
private:
	Ball m_ball;
	Player m_player1, m_player2;
	bool active = false;
	bool playing = false;
	RECT m_WInfo;

public:
	GameMaster();

	GameMaster(RECT Client);

	CRect GetBallPosition();
	CRect GetPaddle(int player_no);

	void SetBallSize(CRect client);
	void SetPlayerSize(CRect client,int player_no);
	void SetClient(CRect client);
	void SetPosition(CRect Position);
	void BallSpeed();
	void PlayerMove(int player, int up_down);
	void SetPlaying();

	bool BallMove();
	bool Status();
	bool PlayingStatus();
	bool CollisionCheck();
	bool Score( int player);

	int GetScore(int player);

};