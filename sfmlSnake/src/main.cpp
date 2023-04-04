#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <cstdlib>




int main()
{
 
    srand((unsigned)time(NULL));
    int randomX;
    int randomY;

    
    sf::RenderWindow window(sf::VideoMode(800, 800), "Snake Game");
    window.setFramerateLimit(10);
    

    sf::RectangleShape snakeBodyPiece;
    
    snakeBodyPiece.setFillColor(sf::Color::Green);
    snakeBodyPiece.setSize(sf::Vector2f(20.f, 20.f));
    int headDirection = 1;// 1-North 2-East 3-South 4-west

    bool baitEaten = true;
    bool gameEnded = false;
 
    std::vector<sf::RectangleShape> snake(4, snakeBodyPiece);
    sf::Vector2f oldPos;
    sf::Vector2f oldPos_Temp;
    snake[0].setPosition(sf::Vector2f(400.f, 400.f));
    for (size_t i=1; i < snake.size(); i++) {
        snake[i].setPosition(snake[i - 1].getPosition().x, snake[i - 1].getPosition().y+20);
    }
    snake[0].setFillColor(sf::Color{ 19,137,34 });

    sf::RectangleShape bait;
    bait.setFillColor(sf::Color{ 251,129,20 });
    bait.setSize(sf::Vector2f(20.f, 20.f));

    

    while (window.isOpen())
    {
        randomX = 2 + (rand() % 19);
        randomY = 2 + (rand() % 19);

        sf::Vector2f headPos = snake[0].getPosition();

        if (headPos.x < 0 || headPos.y < 0 || headPos.x > 780 || headPos.y > 780)
            gameEnded = true;
        else
            gameEnded = false;

        if(!gameEnded){
            for (size_t i = 1; i < snake.size(); i++) {
               
                if (snake[0].getPosition() == snake[i].getPosition()) {
                    gameEnded = true;
                    break;
                }

                else {
                    gameEnded = false;
                  
                }
            }
                
        }
        std::cout << gameEnded;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (!gameEnded) {
                if (event.type == sf::Event::KeyPressed) {

                    if (event.key.code == sf::Keyboard::Up && headDirection != 3)
                        headDirection = 1;
                    if (event.key.code == sf::Keyboard::Down && headDirection != 1)
                        headDirection = 3;
                    if (event.key.code == sf::Keyboard::Left && headDirection != 2)
                        headDirection = 4;
                    if (event.key.code == sf::Keyboard::Right && headDirection != 4)
                        headDirection = 2;
                }
            }
        }

        if (!gameEnded) {
            switch (headDirection) {
            case 1:
                oldPos = snake[0].getPosition();
                snake[0].move(sf::Vector2f(0.f, -20.f));
                break;
            case 2:
                oldPos = snake[0].getPosition();
                snake[0].move(sf::Vector2f(20.f, 0.f));
                break;
            case 3:
                oldPos = snake[0].getPosition();
                snake[0].move(sf::Vector2f(0.f, 20.f));
                break;
            case 4:
                oldPos = snake[0].getPosition();
                snake[0].move(sf::Vector2f(-20.f, 0.f));
                break;
            }
        
            
            for (size_t i = 1; i < snake.size(); i++) {
                sf::Vector2f oldPos_Temp = oldPos;
                oldPos = snake[i].getPosition();
                snake[i].setPosition(oldPos_Temp);
            }

            if (baitEaten) {
                bait.setPosition(randomX * 40, randomY * 40);
                baitEaten = false;
                snake.push_back(snakeBodyPiece);
            
            }
            if (snake[0].getPosition() == bait.getPosition()) {
                baitEaten = true;
            }
            
            

        }
        
        window.clear();
        window.draw(bait);

        for (size_t i = 0; i < snake.size(); i++) {
            window.draw(snake[i]);
        }

        
        
        

        window.display();

    }

    return 0;
}