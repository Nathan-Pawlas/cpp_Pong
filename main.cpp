#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Paddle.h"
#include "Ball.h"




int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEGIHT), "Pong");
    window.setFramerateLimit(fps);

    //Instantiate Player Paddles!
    Paddle p1(100, (SCREEN_HEGIHT / 2) + 40);
    Paddle p2(SCREEN_WIDTH - 100, (SCREEN_HEGIHT / 2) + 40);

    Ball ball;

    while (window.isOpen())
    {
        sf::Event event;
        if (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //Handle Player Inputs
        if (sf::Keyboard().isKeyPressed(sf::Keyboard().W))
            p1.y_pos -= speed;
        if (sf::Keyboard().isKeyPressed(sf::Keyboard().S))
            p1.y_pos += speed;
        if (sf::Keyboard().isKeyPressed(sf::Keyboard().Up))
            p2.y_pos -= speed;
        if (sf::Keyboard().isKeyPressed(sf::Keyboard().Down))
            p2.y_pos += speed;

        ball.physics(&p1, &p2);

        window.clear();
        p1.update(&window);
        p2.update(&window);
        ball.update(&window);
        window.display();
    }

    return 0;
}