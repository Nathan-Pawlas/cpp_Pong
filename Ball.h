#pragma once
#pragma once
#include "Constants.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <random>
#include <SFML/Audio.hpp>

class Ball
{
public:
	Ball()
	{
		shape = sf::CircleShape(8);
		shape.setFillColor(sf::Color().White);
		shape.setPosition((float)SCREEN_WIDTH / 2, (float)SCREEN_HEGIHT / 2);
		collider.width = 8;
		collider.height = 8;
		y_velocity = (float)(rand() % 4 + 1);
	}
	~Ball()
	{

	}

	void update(sf::RenderWindow* window)
	{
		draw(window);
		setPosition();

		if (shape.getPosition().x < 0)
		{
			score2 += 1;
			shape.setPosition((float)SCREEN_WIDTH / 2, (float)SCREEN_HEGIHT / 2);
			y_velocity = (float)(rand() % 8) - 4;
			x_velocity = -3;
		}
		else if (shape.getPosition().x > SCREEN_WIDTH)
		{
			score1 += 1;
			shape.setPosition((float)SCREEN_WIDTH / 2, (float)SCREEN_HEGIHT / 2);
			y_velocity = (float)(rand() % 8) - 4;
			x_velocity = 3;
		}
	}

	void physics(Paddle* p1, Paddle* p2, sf::Sound* sound)
	{
		if (this->collider.intersects(p1->collider) || this->collider.intersects(p2->collider))
		{
			x_velocity *= -(1 + scale_factor);
			y_velocity += ((float)rand() / RAND_MAX) * (0.25 - 0.01) + 0.01;
			sound->play();
		}

		if (shape.getPosition().y + 4 > SCREEN_HEGIHT || shape.getPosition().y < 0)
		{
			y_velocity *= -(1 + scale_factor);
		}
	}

public:
	float x_velocity = 3;
	float y_velocity = 0;
	sf::Rect<float> collider;
	int score1 = 0;
	int score2 = 0;
	float scale_factor = 0.15;

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