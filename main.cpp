#include <iostream>
#include <SFML/Graphics.hpp>

const int width = 900;
const int height = 700;
const float x0 = width / 2;
const float y0 = height / 2;
const float X1plank = 50;
const float X2plank = 850;

const float height_p = 60;

enum class Direction {UP , Down};
Direction direction;

bool Gameover = false;

class Game : public sf::Drawable, public sf::Transformable, public Shapes
{   
    protected:
    const float weight_p = 5;
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
    void Move(Direction direction);
    void Logic();

public:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

class Shapes
{
    public:
        const float weight_p = 5;
         sf::CircleShape ball()
         {
            return sf::CircleShape();
         }
         sf::RectangleShape plank()
         { 
             return sf::RectangleShape();
         }
         sf::RectangleShape plank2()
         {
             sf::RectangleShape();
         }
};



 void  Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{   
    states.transform *= getTransform();
    sf::RectangleShape shape(sf::Vector2f(850.f, 650.f));
    shape.setFillColor(sf::Color::Transparent);
    shape.setPosition(25.f, 25.f);
    shape.setOutlineThickness(2.f);
    shape.setOutlineColor(sf::Color(255, 255, 255));
    target.draw( shape, states);
    

    sf::RectangleShape plank(sf::Vector2f(5.f, 60.f));
    plank.setFillColor(sf::Color::White);
    plank.setPosition(X1plank, Y1plank);
    target.draw(plank , states);

    sf::RectangleShape plank2(sf::Vector2f(5.f, 60.f));
    plank2.setFillColor(sf::Color::White);
    plank2.setPosition(X2plank, Y2plank);
    target.draw(plank2 , states);

    sf::CircleShape ball(5.f);
    ball.setFillColor(sf::Color::White);
    ball.setPosition(diffx, diffy);
    ball.move(Bx, By);
    target.draw(ball , states);

    
    
}

void Game::Move (Direction direction)
{
    Shapes s;
  if(direction == Direction::UP)  s.plank().sf::Transformable::move(0.f, -10.f);
  if(direction == Direction::Down) s.plank2().sf::Transformable::move(0.f, 10.f);; 
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
    Shapes s;
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

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) direction == Direction::UP;

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                    direction = Direction::Down;
            }
        }

        window.clear();
        window.draw(game);
        window.display();
    }
    return 0;
}
