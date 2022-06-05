#ifndef SPOLAWNIACZE_H
#define SPOLAWNIACZE_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "player.h"

class Spolawniacze:public sf::Sprite
{
public:
    Spolawniacze(sf::Texture &);
    sf::Vector2f returnv();
private:
    int vx;
    int vy;
};

#endif // SPOLAWNIACZE_H
