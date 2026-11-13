#pragma once

#include <SFML/Graphics.hpp>

class character1 {
private:
    sf::Texture Texture;
    float speed = 900.f;


public:
    sf::Sprite Sprite;

    character1();
    void initialize();
    void load();
    void update(float dt);
    void draw(sf::RenderWindow& window);
    sf::Vector2f getPosition() const;
};
