#include <SFML/Graphics.hpp>
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

 sf::Vector2f normalizedVector(sf::Vector2f vector){
    float magnitude=sqrt(vector.x*vector.x + vector.y*vector.y);
    sf::Vector2f normalvector;
    normalvector.x=vector.x/magnitude;
    normalvector.y=vector.y/magnitude;
    return normalvector;
}
   
int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My Game");
    window.setFramerateLimit(60);

  
    sf::RectangleShape bullet(sf::Vector2f(10.f,3.f));
    bullet.setFillColor(sf::Color::Red);
    float bulletspeed=5;
    sf::Vector2f path;

    sf::Texture enemyTexture;
    if(!enemyTexture.loadFromFile("C:/Users/ganes/Downloads/rpg-poison-skeleton-toxic-green-248-v5-2026-03-03T17-02-45 (1).png")){
        cout<<"Hell yeah";
        return 1;
    }
    sf::Sprite enemySprite(enemyTexture);
    enemySprite.setPosition(sf::Vector2f(50.f,25.f));

   sf::Texture playerTexture;
if (!playerTexture.loadFromFile("C:/Users/ganes/Downloads/player.png")) {
    cout << "Could not load the image\n";
    return 1;
}
    sf::Sprite playerSprite(playerTexture);
    playerSprite.setPosition(sf::Vector2f(650.f, 460.f));
    playerSprite.setTextureRect(sf::IntRect({0,0},{32,48}));
   
    bullet.setPosition(playerSprite.getPosition());
    sf::Clock clock;
    const float speed = 900.f; 

    vector<sf::RectangleShape>bullets;
    // this is my game loop
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
            for(size_t i=0;i<bullets.size();i++){
                sf::Vector2f path=enemySprite.getPosition()-bullet.getPosition();
                path=normalizedVector(path);
            }
        }
   // this is my update or event loop 

   
        float dt = clock.restart().asSeconds();

        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
            bullets.push_back(sf::RectangleShape(sf::Vector2f(10.f,3.f)));
            bullets[bullets.size()-1].setPosition(playerSprite.getPosition());
        } 
        for(size_t i=0;i<bullets.size();i++){
    sf::Vector2f toEnemy = enemySprite.getPosition() - bullets[i].getPosition();
    bullets[i].move(normalizedVector(toEnemy) * bulletspeed);
}
      

        sf::Vector2f direction{0.f, 0.f};
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))  direction.x -= 1.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) direction.x += 1.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))    direction.y -= 1.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))  direction.y += 1.f;

        playerSprite.move(direction * speed * dt);
   // this is my display section 
        window.clear(sf::Color::Black);
        for(size_t i=0;i<bullets.size();i++){
              window.draw(bullets[i]);
        }
        window.draw(playerSprite);
        window.draw(enemySprite);
        window.display();
    }
    cout<<"TRY AGAIN LOSER :)";
    return 0;

}

