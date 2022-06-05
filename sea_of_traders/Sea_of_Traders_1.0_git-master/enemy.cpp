#include "enemy.h"
#include <cmath>
Enemy::Enemy(sf::Texture &baza)
{
    setTexture(baza);
    vx=100;
    vy=100;
    kierunek = sf::Vector2f(rand()%3-1,rand()%3-1);
    setTextureRect(sf::IntRect(32,32,32,32));
}
void Enemy::Animate(sf::Time elapsed, std::vector<Obiekty> &a)
{
    move(kierunek.x*vx*elapsed.asSeconds(),kierunek.y*vy*elapsed.asSeconds());
    sf::Vector2f PozycjaEle;
    sf::Vector2f Pozycja = sf::Vector2f(this->getPosition().x+this->getGlobalBounds().width/2,this->getPosition().y+this->getGlobalBounds().height/2);

    for(auto &p:a)
    {
        PozycjaEle = sf::Vector2f(p.getPosition().x+p.getGlobalBounds().width/2,p.getPosition().y+p.getGlobalBounds().height/2);
        double i = std::pow(std::abs(Pozycja.x-PozycjaEle.x),2)+std::pow(std::abs(Pozycja.y-PozycjaEle.y),2);
        if(sqrt(i)<=16*sqrt(2))
        {   
            if(Pozycja.x<PozycjaEle.x)
            {
                kierunek.x=rand()%2-1;
            }
            if(Pozycja.x>PozycjaEle.x)
            {
                kierunek.x=rand()%2;
            }
            if(Pozycja.y<PozycjaEle.y)
            {
                kierunek.y=rand()%2-1;
            }
            if(Pozycja.y>PozycjaEle.y)
            {
                kierunek.y=rand()%2;
            }
        }
    }
    if(this->getPosition().x<0)
    {
        kierunek.x = 1;
    }
    if(this->getPosition().x>1000-32)
    {
        kierunek.x = -1;
    }
    if(this->getPosition().y<0)
    {
        kierunek.y = 1;
    }
    if(this->getPosition().y>600-32)
    {
        kierunek.y = -1;
    }

}
void Enemy::resetposition()
{
    setPosition(rand()%950+50,rand()%400);
}
void Enemy::Bounce(sf::Sprite &a)
{
    if(this->getGlobalBounds().intersects(a.getGlobalBounds()))
    {
        kierunek.x*=-1;
        kierunek.y*=-1;
    }
}
void Enemy::IT()
{
    this->setTextureRect(sf::IntRect(32+kierunek.x*32,32+kierunek.y*32,32,32));
}
