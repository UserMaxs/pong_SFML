#include <iostream>
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>

const int width = 900;
const int height = 700;
const float x0 = width / 2;
const float y0 = height / 2;
const float X1plank = 50;
const float X2plank = 850;

enum class Direction {UP , Down};
Direction direction;

bool Gameover = false;



class Game : public sf::Drawable, public sf::Transformable
{   
    protected:
    float speedx = 1;
    float speedy = 1;
    float Y1plank = height / 2;
    float Y2plank = height / 2;
    float Bx;
    float By;
    float diffx;
    float diffy;
    float diry;
    float ditx;

public:
    void Move();
    void Logic();

public:
    virtual void Draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

void Game::Move ()
{
   if (direction == Direction::UP) 
}

 void Game::Draw(sf::RenderTarget& target, sf::RenderStates) const
{  
    sf::RectangleShape shape(sf::Vector2f(850.f, 650.f));
    shape.setFillColor(sf::Color::Transparent);
    shape.setPosition(25.f, 25.f);
    shape.setOutlineThickness(2.f);
    shape.setOutlineColor(sf::Color(255, 255, 255));

    sf::RectangleShape plank(sf::Vector2f(5.f, 60.f));
    plank.setFillColor(sf::Color::White);
    plank.setPosition(X1plank, Y1plank);

    sf::RectangleShape plank2(sf::Vector2f(5.f, 60.f));
    plank2.setFillColor(sf::Color::White);
    plank2.setPosition(X2plank, Y2plank);

    sf::CircleShape ball(5.f);
    ball.setFillColor(sf::Color::White);
    ball.setPosition(diffx, diffy);
    ball.move(Bx, By);
    sf::Text text;
    text.setString("Score");
}

void Game::Logic()
{
    if (Bx == 870 || Bx == 30)
        Bx = width / 2;
    if (By == 670 || By == 30)
        By = width / 2;

     while (!Gameover)
    {
        Bx = x0 + 1 * speedx;
        By = y0 + 1 * speedy;
        diffx = Bx - x0;
        diffy = By - y0;
        
    }

}



int main()
{
    Game game;
    sf::RenderWindow window(sf::VideoMode(width, height), "Pong 2.0");
    
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            

            if (event.type == sf::Event::KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    window.close();

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                    plank2.Move(0.f, -10.f);

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                    plank2.Move(0.f, 10.f);
            }
        }

        window.clear();
        window.draw(game);
        window.display();
    }
    return 0;
}
