#include "bulletmath.h"
#include<SFML/Audio.hpp>
#include<iostream>
#include <cmath>

void bullet::initialize(sf::Vector2f position, sf::Vector2f target) {
    shape.setPosition(position);

    const sf::Vector2f offset = target - position;
    const float magnitude = std::sqrt(offset.x * offset.x + offset.y * offset.y);
    direction = magnitude > 0.f
        ? sf::Vector2f(offset.x / magnitude, offset.y / magnitude)
        : sf::Vector2f{};
  
}

void bullet::load() {
    shape.setSize(sf::Vector2f(10.f, 3.f));
    shape.setFillColor(sf::Color::Red);
    
}

void bullet::update(float dt) {
    shape.move(direction * speed * dt);
}

void bullet::display(sf::RenderWindow& window) {
    window.draw(shape);
}