#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Snake Game");
    sf::RectangleShape snakeBodyPiece;
    snakeBodyPiece.setFillColor(sf::Color::Green);
    snakeBodyPiece.setSize(sf::Vector2f(20.f, 20.f));
    std::vector<sf::RectangleShape> snake(3, snakeBodyPiece);
    int headDirection = 1;// 1-North 2-East 3-South 4-west
    std::cout << sizeof(snake);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        switch (headDirection)
            case 1:
                for (size_t i; i < snake.size(); i++) {

                }
        


        window.clear();


        window.draw(snakeBodyPiece);
        


        window.display();

    }

    return 0;
}