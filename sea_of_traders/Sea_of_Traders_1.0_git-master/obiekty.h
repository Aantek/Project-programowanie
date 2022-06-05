 #ifndef OBIEKTY_H
#define OBIEKTY_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Obiekty : public sf::Sprite
{
public:
    Obiekty(sf::Texture&);
    Obiekty(sf::Texture &, int, int);
    Obiekty(sf::Texture &, bool);
    void animate(sf::Time,double,sf::Sprite&,sf::Sprite &);
    void bounce(sf::Sprite &,sf::Sprite &);
    bool cansearch();
private:
    bool can_search = false;
    int gold;
    float velocity_x=200;
    float velocity_y=0;
};

#endif // OBIEKTY_H
