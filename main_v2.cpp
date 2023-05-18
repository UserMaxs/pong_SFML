#include <iostream>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include <ctime>
using namespace std;


class Pong
{   
private:
    const unsigned int width;
    const unsigned int height;
    const float x0 = width / 2;
    const float y0 = height / 2;
    int score_l = 0;
    int score_R = 0;
    int hits;

    float xspeed = 1;
    float yspeed = 1;
    
   
    sf::RenderWindow *window;
    sf::CircleShape ball;
    sf::RectangleShape frame;
    sf::RectangleShape plank;
    sf::RectangleShape plank2;
public:
    Pong(sf::RenderWindow *win ) : width(win->getSize().x), height(win->getSize().y)
    {
        window = win;
        ball = sf::CircleShape(5.f);
        frame = sf::RectangleShape (sf::Vector2f(850.f, 550.f));
        plank = sf::RectangleShape (sf::Vector2f(5.f, 70.f));
        plank2 = sf::RectangleShape (sf::Vector2f(5.f, 70.f));
    };

    

    void Game()
    {

        sf::CircleShape ball(5.f);
        ball.setPosition(x0, y0);

        frame.setFillColor(sf::Color::Transparent);
        frame.setPosition(25.f, 25.f);
        frame.setOutlineThickness(2.f);
        frame.setOutlineColor(sf::Color(255, 255, 255));

        plank.setFillColor(sf::Color::White);
        plank.setPosition(50.f, 350.f);

        plank2.setFillColor(sf::Color::White);
        plank2.setPosition(850.f, 350.f);

       
        


        while (window->isOpen())
        {
            sf::Event event;
            while (window->pollEvent(event))
            {
                
                if (event.type == sf::Event::Closed)
                    window->close();
                if (event.type == sf::Event::KeyPressed)
                {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window->close();
                    if (plank2.getPosition().y > 35 ) 
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) plank2.move( 0.f,-12.f);
                    if (plank2.getPosition().y < 500) 
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) plank2.move( 0.f,12.f);
                }
            }

            if (ball.getPosition().y + ball.getRadius() * 2 > height - 25 ||
                ball.getPosition().y + yspeed < 25) yspeed = -yspeed;

            if ((ball.getPosition().x + ball.getRadius() * 2) + xspeed < 60 &&
                (ball.getPosition().x + ball.getRadius() * 2) + xspeed > plank.getPosition().x)
                if (ball.getPosition().y >= plank.getPosition().y && 
                    ball.getPosition().y <= plank.getPosition().y + 70 )
                    {
                         hits++;
                         xspeed = -xspeed;
                          if ( hits >= 3)  
                                if (xspeed <= 2)
                                {
                                    srand( time( 0 ));
                                    xspeed = xspeed + (rand() % 2 + 1) / 2;
                                }
                         
                         
                    }
                     
             if ((ball.getPosition().x + ball.getRadius() * 2) + xspeed > width - 55  &&
                 (ball.getPosition().x + ball.getRadius() * 2) + xspeed < plank2.getPosition().x)
                if (ball.getPosition().y >= plank2.getPosition().y && 
                    ball.getPosition().y <= plank2.getPosition().y + 70 )
                    {
                      hits++;
                      xspeed = -xspeed;
                      if ( hits >= 2)
                        if (xspeed < 2)
                                {
                                    srand( time( 0 ));
                                    xspeed = xspeed - (rand() % 2 + 1) / 2;

                                }
                      
                    }
            

            ball.move(sf::Vector2f(xspeed, yspeed));
            if (ball.getPosition().y > 60 && ball.getPosition().y < 540) 
                plank.setPosition( 50.f , ball.getPosition().y -35);
            if (ball.getPosition().x + ball.getRadius() * 2 > width - 25||
                ball.getPosition().x + xspeed < 40) ;
            if( ball.getPosition().x + ball.getRadius() * 2 > width - 25)  
            { 
                ball.setPosition(sf::Vector2f(450, 350));
                srand( time( 0 ));
                xspeed =  1 * ((rand() % 2)* 2 - 1);
                yspeed =  1 * ((rand() % 2)* 2 - 1);
            }
            if( ball.getPosition().x + ball.getRadius() * 2 < 25)  
            { 
                ball.setPosition(sf::Vector2f(450, 350));
                srand( time( 0 ));
                xspeed =  1 * ((rand() % 2)* 2 - 1);
                yspeed =  1 * ((rand() % 2)* 2 - 1);
            
            }
           
                 
            window->clear();
            window->draw(frame);
            window->draw(plank);
            window->draw(plank2);
            window->draw(ball);
            window->display();

            this_thread::sleep_for(chrono::milliseconds(5));
        }
    };
};


int main()
{

sf::RenderWindow window(sf::VideoMode(900, 600), "Pong 2.0" , sf::Style::Default & ~sf::Style::Resize);

Pong p(&window);
p.Game();

}
