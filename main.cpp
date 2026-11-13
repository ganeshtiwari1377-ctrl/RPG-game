#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <iostream>
#include <vector>
using namespace std;
#include "projectfiles/bulletmath.h"
#include "projectfiles/Player.h"




int main() {

    sf::RenderWindow window(sf::VideoMode({800, 600}), "My Game");
    window.setFramerateLimit(60);

    sf::Texture background_image;
    if(!background_image.loadFromFile("C:/Users/ganes/Downloads/boss enemy/Ember-Fire-Dragon-Asset-Pack/Backgrounds/volcanic-wasteland.png")){
        std::cout << "Could not load background image\n";
        return 1;
    }

    sf::Sprite backgroundSprite(background_image);
    const sf::Vector2u textureSize = background_image.getSize();
    backgroundSprite.setScale({
        800.f / static_cast<float>(textureSize.x),
        600.f / static_cast<float>(textureSize.y)
    });
   

    sf::Texture enemyTexture;
    if(!enemyTexture.loadFromFile("C:/Users/ganes/Downloads/boss enemy/Ember-Fire-Dragon-Asset-Pack/Sprites/Breath/Left/breath_48f_sheet.png")){
        std::cout << "Hell yeah";
        return 1;
    }
    sf::Sprite enemySprite(enemyTexture);
    enemySprite.setPosition(sf::Vector2f(50.f,25.f));
    enemySprite.setTextureRect(sf::IntRect({0,0},{640,360}));
    enemySprite.scale(sf:: Vector2f(1, 1));
    sf::RectangleShape enemyHealth;
      enemyHealth.setFillColor(sf::Color::Yellow);
      enemyHealth.setSize({100.f, 5.f});
      enemyHealth.setPosition(enemySprite.getPosition());
    
   

    character1 player;
    player.initialize();
    player.load();

    sf::Clock clock;

    sf::SoundBuffer bullet_sound;
    if(!bullet_sound.loadFromFile("C:/Users/ganes/Downloads/universfield-pistol-shot-278821.wav")){
        cout<<"could not load from file ";
    }

    sf::Sound bullet_Sound(bullet_sound);

    std::vector<bullet> bullets;
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
      

        float dt = clock.restart().asSeconds();
        player.update(dt);

    
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) ||  sf::Joystick::isButtonPressed(0,0)) {
            bullets.emplace_back();
            bullets.back().load();
            bullets.back().initialize(player.getPosition()+sf::Vector2f(128.f,128.f), enemySprite.getPosition());
            bullet_Sound.play();
        }
       
        
    

        for (bullet& currentBullet : bullets)
            currentBullet.update(dt);

        window.clear();
        window.draw(backgroundSprite);

        player.draw(window);
        window.draw(enemySprite);
        window.draw(enemyHealth);
        for (bullet& currentBullet : bullets)
            currentBullet.display(window);
        window.display();
    }
    std::cout << "TRY AGAIN LOSER :)";
    return 0;
}
