#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Paddle.h"
#include "Ball.h"
#include "UI.h"
#include <SFML/Audio.hpp>




int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEGIHT), "Pong");
    window.setFramerateLimit(fps);

    //Instantiate Player Paddles!
    Paddle p1(100, (SCREEN_HEGIHT / 2) + 40);
    Paddle p2(SCREEN_WIDTH - 100, (SCREEN_HEGIHT / 2) + 40);

    Ball ball;
    UI ui;
    sf::SoundBuffer buffer;
    buffer.loadFromFile("beep-03.wav");
    sf::Sound sound;
    sound.setBuffer(buffer);

    bool round_over = false;

    while (window.isOpen())
    {
        sf::Event event;
        if (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard().isKeyPressed(sf::Keyboard().Q))
            window.close();

        if (sf::Keyboard().isKeyPressed(sf::Keyboard().Space))
        {
            ball.score1 = 0;
            ball.score2 = 0;
            round_over = false;
            ui.setText("", &ui.genText);
        }

        if (!round_over)
        {
            //Handle Player Inputs
            if (sf::Keyboard().isKeyPressed(sf::Keyboard().W))
                p1.y_pos -= speed;
            if (sf::Keyboard().isKeyPressed(sf::Keyboard().S))
                p1.y_pos += speed;
            if (sf::Keyboard().isKeyPressed(sf::Keyboard().Up))
                p2.y_pos -= speed;
            if (sf::Keyboard().isKeyPressed(sf::Keyboard().Down))
                p2.y_pos += speed;

            ball.physics(&p1, &p2, &sound);

            

            ui.setText(std::to_string(ball.score1), &ui.score1);
            ui.setPosition(200, 5, &ui.score1);

            ui.setText(std::to_string(ball.score2), &ui.score2);
            ui.setPosition(SCREEN_WIDTH - 200, 5, &ui.score2);

            window.clear();

            p1.update(&window);
            p2.update(&window);
            ball.update(&window);
            
            if (ball.score1 >= 5)
            {
                ui.setText("Player 1 Wins!", &ui.genText);
                ui.setPosition((SCREEN_WIDTH / 2) - 125, SCREEN_HEGIHT / 2, &ui.genText);
                round_over = true;
            }
            else if (ball.score2 >= 5)
            {
                ui.setText("Player 2 Wins!", &ui.genText);
                ui.setPosition((SCREEN_WIDTH / 2) - 125, SCREEN_HEGIHT / 2, &ui.genText);
                round_over = true;
            }
        }


        ui.update(&window);
        window.display();
    }

    return 0;
}