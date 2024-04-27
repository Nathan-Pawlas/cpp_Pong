#pragma once
#include "Constants.h"
#include <SFML/Graphics.hpp>

class Paddle
{
public:
	Paddle(float x, float y)
	{
		shape = sf::RectangleShape(sf::Vector2f(20, 80));
		x_pos = x;
		y_pos = y;
		setColor(sf::Color().White);
	}
	~Paddle()
	{

	}

	void update(sf::RenderWindow* window)
	{
		draw(window);
		setPosition();
	}

	void setColor(sf::Color color)
	{
		shape.setFillColor(color);
	}

public:
	float x_pos = 0;
	float y_pos = 0;

private:
	void draw(sf::RenderWindow* window)
	{
		window->draw(shape);
	}

	void setPosition()
	{
		//Keep Player in the Bounds of the Screen
		if (y_pos < (SCREEN_HEGIHT - shape.getSize().y) && y_pos > 0)
			shape.setPosition(sf::Vector2f(x_pos, y_pos));
	}

private:
	sf::RectangleShape shape;
};