#pragma once

#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

class bullet {
private:
    sf::RectangleShape shape;
    sf::Vector2f direction{};
    float speed = 300.f;

public:
    void initialize(sf::Vector2f position, sf::Vector2f target);
    void load();
    void update(float dt);
    void display(sf::RenderWindow& window);
    void sound();
};
