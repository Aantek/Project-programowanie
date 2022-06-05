#include "obiekty.h"
#include <time.h>
#include <cstdlib>
Obiekty::Obiekty(sf::Texture &baza)
{
    this->setTexture(baza);
}
Obiekty::Obiekty(sf::Texture &baza, int wx,int wy)
{
    this->setTexture(baza);
    velocity_x=wx;
    velocity_y=wy;
}
Obiekty::Obiekty(sf::Texture &baza, bool can_S)
{
    this->setTexture(baza);
    if(can_S)
    {
    this->can_search=true;
    gold = rand()%200+50;
    }
    velocity_x=0;
    velocity_y=0;
}
void Obiekty::animate(sf::Time elapsed,double poziom, sf::Sprite &start,sf::Sprite &pulapka)
{
    poziom/=5;
    move(velocity_x*poziom*elapsed.asSeconds(),velocity_y*poziom*elapsed.asSeconds());
    bounce(start,pulapka);
}
void Obiekty::bounce(sf::Sprite &start,sf::Sprite &pulapka)
{
    auto object_bounds = this->getGlobalBounds();
    if(object_bounds.left < 0)
    {
        this->velocity_x = std::abs(this->velocity_x);
    }

    if(object_bounds.top < 0)
    {
        velocity_y = std::abs(velocity_y);
    }

    if(object_bounds.left+object_bounds.width > 1000)
    {
        velocity_x = -std::abs(velocity_x);
    }

    if(object_bounds.top+object_bounds.height > 600)
    {
        velocity_y = -std::abs(velocity_y);
    }
    if(getGlobalBounds().intersects(start.getGlobalBounds()))
    {
        velocity_y = -std::abs(velocity_y);
        velocity_x = std::abs(velocity_x);
    }
    if(getGlobalBounds().intersects(pulapka.getGlobalBounds()))
    {
        velocity_y = std::abs(velocity_y);
        velocity_x = std::abs(velocity_x);
    }
}
bool Obiekty::cansearch()
{
    if(this->can_search)
    {
        return true;
    }
    else
    {
        return false;
    }
}
