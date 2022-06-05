#include "spolawniacze.h"

Spolawniacze::Spolawniacze(sf::Texture &baza)
{
    setTexture(baza);
    setPosition(rand()%950+50,rand()%400);
    setScale(3,rand()%5+1);
    vx=0;
    vy=(rand()%100+50)/2;
}
sf::Vector2f Spolawniacze::returnv()
{
    return sf::Vector2f(vx,vy);
}
