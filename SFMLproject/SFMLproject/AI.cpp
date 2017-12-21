#include "AI.h"
using namespace std;

namespace tennis_game
{
	void AI::Movement(Character &player, Ball &ball, sf::Time elapsed)
	{
		if (!ball.GetBallDirection() || ball.GetBallDirection())
		{
			if (ball.GetBallPosition().x > player.GetRaquetSprite().getPosition().x)
			{
				player.MoveRight(elapsed);
			}

			else if (ball.GetBallPosition().x < player.GetRaquetSprite().getPosition().x)
			{
				player.MoveLeft(elapsed);
			}
		}
	}
	void AI::Hit(Character &player, Ball &ball, sf::Time elapsed)
	{
		if (!ball.GetBallDirection() && (ball.GetBallPosition().y - player.GetPlayerPosition().y) < 150)
		{
			player.SetShotPowerMultiplier(0.1);
			player.ShotDrive();
		}
	}



	AI::AI()
	{
	}


	AI::~AI()
	{
	}
	void AI::ProcessAI(Character &player, Ball &ball, sf::Time elapsed)
	{
		Movement(player, ball, elapsed);
		Hit(player, ball, elapsed);
	}
}
