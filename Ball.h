#pragma once
#pragma once
#include "Constants.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <random>

class Ball
{
public:
	Ball()
	{
		shape = sf::CircleShape(8);
		shape.setFillColor(sf::Color().White);
		shape.setPosition(SCREEN_WIDTH / 2, SCREEN_HEGIHT / 2);
		collider.width = 8;
		collider.height = 8;
		y_velocity = rand() % 4 + 1;
	}
	~Ball()
	{

	}

	void update(sf::RenderWindow* window)
	{
		draw(window);
		setPosition();
	}

	void physics(Paddle* p1, Paddle* p2)
	{
		if (this->collider.intersects(p1->collider) || this->collider.intersects(p2->collider))
			x_velocity *= -1;


		if (shape.getPosition().y + 4 > SCREEN_HEGIHT || shape.getPosition().y < 0)
			y_velocity *= -1;
	}

public:
	float x_velocity = 3;
	float y_velocity = 0;
	sf::Rect<float> collider;

private:
	void draw(sf::RenderWindow* window)
	{
		window->draw(shape);
	}

	void setPosition()
	{
		shape.move(sf::Vector2f(x_velocity, y_velocity));
		collider.top = shape.getPosition().y;
		collider.left = shape.getPosition().x;
	}


private:
	sf::CircleShape shape;

};