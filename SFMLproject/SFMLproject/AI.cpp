#include "AI.h"
using namespace std;

namespace tennis_game
{
	AI::AI()
	{
	}


	AI::~AI()
	{
	}
	void AI::ProcessAI(Character &player, Ball &ball, sf::Time elapsed)
	{
		if (!ball.GetBallDirection() || ball.GetBallDirection())
		{
			if (ball.GetBallPosition().x > player.GetPlayerPosition().x)
			{
				player.MoveRight(elapsed);
			}

			else if (ball.GetBallPosition().x < player.GetPlayerPosition().x)
			{
				player.MoveLeft(elapsed);
			}
		}
	}
}
