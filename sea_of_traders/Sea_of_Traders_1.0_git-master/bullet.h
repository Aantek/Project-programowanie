#ifndef BULLET_H
#define BULLET_H
#include <iostream>
#include "obiekty.h"
#include "player.h"

class Bullet : public sf::Sprite
{
public:
    Bullet(Player &,sf::Texture &);
    void Animate(sf::Time &);
private:
    int vx;
    int vy;
};

#endif // BULLET_H
