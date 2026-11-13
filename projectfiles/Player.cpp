#include "Player.h"
#include <SFML/Graphics.hpp>
#include<cmath>
#include<iostream>



 character1::character1() : Sprite(Texture) {}


void character1::initialize() {
    Sprite.setPosition(sf::Vector2f(100.f, 100.f));
    Sprite.setTextureRect(sf::IntRect({0,0},{128,128}));
    Sprite.scale(sf:: Vector2f(2, 2));
}

void character1::load() {
    if (!Texture.loadFromFile("C:/Users/ganes/Downloads/hero/Gangsters_1/Idle.png")) {
    }
    Sprite.setTexture(Texture);
    Sprite.setPosition(sf::Vector2f(100.f, 100.f));
    Sprite.setTextureRect(sf::IntRect({0,0},{128,128}));
}

void character1::update(float dt) {
    sf::Vector2f direction{0.f, 0.f};
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) direction.x -= 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) direction.x += 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) direction.y -= 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) direction.y += 1.f;

    
    if(sf::Joystick::isConnected(0)){
    const float minimum_movement =15.f;
    float x= sf::Joystick::getAxisPosition(0,sf::Joystick::Axis::X);
    float y= sf::Joystick::getAxisPosition(0,sf::Joystick::Axis::Y);
    if (std::abs(x)>minimum_movement)  direction.x+=x/100.f;
    if (std::abs(y)>minimum_movement)  direction.y+=y/100.f;
  
}   
    if(sf::Joystick::isButtonPressed(0,0)){
        
    }



float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
if (length > 1.f)
direction = direction / length;

Sprite.move(direction * speed * dt);

     

}

void character1::draw(sf::RenderWindow& window) {
    window.draw(Sprite);


}

sf::Vector2f character1::getPosition() const {
    return Sprite.getPosition();
}
