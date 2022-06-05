#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include "spolawniacze.h"

class Player : public sf::Sprite
{
public:
    Player(sf::Texture &baza);
    void Animate(sf::Time);
    void addMoney(int a);
    void showMoney();
    void upgrade(sf::Texture &a);
    int retrunMoney();
    void LoseMoney(int a);
    void loseLives();
    int returnLives();
    void resetLives();
    void ShowStatistic(int level);
    void AddHit();
    void resetPosition();
    void hearts(sf::Sprite &);
    int returnHit();
    bool returnUpgrade();
    sf::Vector2f returnkierunek();
    void Bullets(sf::Sprite &);
    void resetBullet();
    int returnBullet();
    void BulletLose();
    void setvelocities(int,int);
    sf::Vector2f returnvelocities();
    void resetVelocities();
    private:
    std::string name;
    int lives;
    float velocity_x = 0;
    float velocity_y = 0;
    int gold = 0;
    int lives_max;
    bool afterupgrage = false;
    int iloscUderzonychObiektow;
    sf::Vector2f kierunek=sf::Vector2f(0,0);
    int bullet_max;
    int bullet;
    int vx_baza;
    int vy_baza;
};

#endif // PLAYER_H
