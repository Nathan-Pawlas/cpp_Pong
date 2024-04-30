#pragma once

#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Paddle.h"
#include "Ball.h"
#include "UI.h"

class GameManager
{
public:
	GameManager()
	{
		//Instantiate Player Paddles!
		Paddle p1(100, (SCREEN_HEGIHT / 2) + 40);
		Paddle p2(SCREEN_WIDTH - 100, (SCREEN_HEGIHT / 2) + 40);

		Ball ball;

	}

private:
	Paddle p1;
	Paddle p2;
	Ball ball;
	UI ui;
};