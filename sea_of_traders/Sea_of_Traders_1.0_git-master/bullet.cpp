#include "bullet.h"

Bullet::Bullet(Player &PlayerOne,sf::Texture &baza)
{
    setTexture(baza);
    setPosition(PlayerOne.getPosition().x+16,PlayerOne.getPosition().y+16);
    vx = PlayerOne.returnkierunek().x*300;
    vy = PlayerOne.returnkierunek().y*300;
}
void Bullet::Animate(sf::Time &elapsed)
{
    move(vx*elapsed.asSeconds(),vy*elapsed.asSeconds());

}
