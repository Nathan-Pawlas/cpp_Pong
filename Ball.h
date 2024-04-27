#pragma once
#pragma once
#include "Constants.h"
#include <SFML/Graphics.hpp>

class Ball
{
public:
	Ball()
	{
		shape = sf::CircleShape(8);
		x_pos = SCREEN_WIDTH / 2;
		y_pos = SCREEN_HEGIHT / 2;
		shape.setFillColor(sf::Color().White);
		shape.setPosition(SCREEN_WIDTH / 2, SCREEN_HEGIHT / 2);
	}
	~Ball()
	{

	}

	void update(sf::RenderWindow* window)
	{
		draw(window);
		setPosition();
	}

		

public:
	float x_pos = 0;
	float y_pos = 0;
	float force = 3;

private:
	void draw(sf::RenderWindow* window)
	{
		window->draw(shape);
	}

	void setPosition()
	{
		
		shape.move(sf::Vector2f(force, 0));
	}

private:
	sf::CircleShape shape;
	
};