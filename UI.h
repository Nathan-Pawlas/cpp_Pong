#pragma once
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>
#include <string>

class UI
{
public:
	UI() 
	{
		score1 = sf::Text();
		score1.setCharacterSize(65); // in pixels, not points!

		score2 = sf::Text();
		score2.setCharacterSize(65); // in pixels, not points!

		genText = sf::Text();
		genText.setCharacterSize(30); // in pixels, not points!

		font.loadFromFile("slkscr.ttf");

		score1.setFont(font);
		score2.setFont(font);
		genText.setFont(font);
	}
	~UI() {}

	void setText(std::string s, sf::Text* text)
	{
		text->setString(s);

		// set the color
		text->setFillColor(sf::Color::White);

		// set the text style
		text->setStyle(sf::Text::Bold);
	}

	void setPosition(float x, float y, sf::Text* text)
	{
		text->setPosition(sf::Vector2f(x, y));
	}

	void update(sf::RenderWindow* window)
	{
		window->draw(score1);
		window->draw(score2);
		window->draw(genText);
	}

public:
	sf::Text score1;
	sf::Text score2;
	sf::Text genText;
	sf::Font font;
};