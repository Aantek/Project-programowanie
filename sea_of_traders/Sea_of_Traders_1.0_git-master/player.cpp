#include "player.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "spolawniacze.h"

sf::Vector2f Player::returnkierunek()
{
    return kierunek;
}
bool Player::returnUpgrade()
{
    return this->afterupgrage;
}
int Player::returnHit()
{
    return iloscUderzonychObiektow;
}
void Player::BulletLose()
{
    bullet--;
}
void Player::Bullets(sf::Sprite &s)
{
    if(afterupgrage)
    {
        s.setTextureRect(sf::IntRect(0,0,40-4*(bullet_max-bullet),8));
    }
    else
    {
       s.setTextureRect(sf::IntRect(0,0,40-8*(bullet_max-bullet),8));
    }
}
void Player::hearts(sf::Sprite &s)
{
    if(afterupgrage)
    {
        s.setTextureRect(sf::IntRect(0,0,80-8*(lives_max-lives),16));
    }
    else
    {
       s.setTextureRect(sf::IntRect(0,0,80-16*(lives_max-lives),16));
    }
}
void Player::resetBullet()
{
    bullet=bullet_max;
}
int Player::returnBullet()
{
    return bullet;
}
void Player::resetPosition()
{
    setPosition(15,570);
}
void Player::Animate(sf::Time elapsed)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if(this->getPosition().y>0)
        {
            move(0, -(velocity_y*elapsed.asSeconds()));
        }
        else
        {
            move(0,0);
        }
        setTextureRect(sf::IntRect(32,0,32,32));
        kierunek=sf::Vector2f(0,-1);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if(this->getPosition().y<600-32)
        {
            move(0, (velocity_y*elapsed.asSeconds()));
        }
        else
        {
            move(0,0);
        }
            setTextureRect(sf::IntRect(32,64,32,32));
            kierunek=sf::Vector2f(0,1);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if(this->getPosition().x>0)
        {
         move(-(velocity_x*elapsed.asSeconds()), 0);
         }
        else
        {
            move(0,0);
        }
         setTextureRect(sf::IntRect(0,32,32,32));
         kierunek=sf::Vector2f(-1,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
         if(this->getPosition().x<1000-32)
         {
            move((velocity_x*elapsed.asSeconds()), 0);
          }
         else
         {
             move(0,0);
         }
         setTextureRect(sf::IntRect(64,32,32,32));
         kierunek=sf::Vector2f(1,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
         setTextureRect(sf::IntRect(64,0,32,32));
         kierunek=sf::Vector2f(1,-1);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
         setTextureRect(sf::IntRect(64,64,32,32));
         kierunek=sf::Vector2f(1,1);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
         setTextureRect(sf::IntRect(0,64,32,32));
         kierunek=sf::Vector2f(-1,1);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
         setTextureRect(sf::IntRect(0,0,32,32));
         kierunek=sf::Vector2f(-1,-1);
    }
}
Player::Player(sf::Texture &baza)
{

    lives = lives_max;
    velocity_x = 100;
    velocity_y = 100;
    iloscUderzonychObiektow=0;
    setTexture(baza);
    setTextureRect(sf::IntRect(32,32,32,32));
    setPosition(15,570);
    lives_max = 5;
    bullet_max = 5;
    vx_baza = 100;
    vy_baza = 100;
}
void Player::addMoney(int a)
{
    gold +=a;
}
void Player::showMoney()
{
     std::cout<<"Ilosc pieniedzy: "<<gold<<std::endl;
}
void Player::resetVelocities()
{
    velocity_x=vx_baza;
    velocity_y=vy_baza;
}
void Player::upgrade(sf::Texture &a)
{
    if(afterupgrage)
    {
        std::cout<<"Nie mozesz juz ulepszyc statku"<<std::endl;
    }
    else
    {
    setTexture(a);
    setTextureRect(sf::IntRect(32,32,32,32));
    velocity_x=150;
    velocity_y=150;
    lives_max*=2;
    bullet_max*=2;
    vx_baza=150;
    vy_baza=150;
    lives = lives_max;
    bullet = bullet_max;
    afterupgrage=true;
    }
}
int Player::retrunMoney()
{
    return gold;
}
void Player::LoseMoney(int a)
{
    if((gold-a)<=0)
    {
        gold = 0;
    }
    else
    {
       gold=-a;
    }
}
void Player::loseLives()
{
    lives--;
}
void Player::setvelocities(int a,int b)
{
   velocity_x=a;
   velocity_y=b;
}
sf::Vector2f Player::returnvelocities()
{
    return sf::Vector2f(velocity_x,velocity_y);
}
int Player::returnLives()
{
    return lives;
}
void Player::resetLives()
{
    lives = lives_max;
}
void Player::ShowStatistic(int level)
{
    std::cout<<"ilosc zagranych poziomow: "<<level<<std::endl;
    std::cout<<"Ilosc zlota: "<<gold<<std::endl;
    if(afterupgrage)
    {
        std::cout<<"Udało ci się ulepszyć statek"<<std::endl;
    }
    else
    {
        std::cout<<"Nie udalo ci sie ulepszyc statku"<<std::endl;
    }
    std::cout<<"Ilosc uderzonych obiektow: "<<iloscUderzonychObiektow<<std::endl;
}
void Player::AddHit()
{
    iloscUderzonychObiektow++;
}
