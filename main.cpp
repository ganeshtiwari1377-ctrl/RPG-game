#include <SFML/Graphics.hpp>
#include<iostream>
using namespace std;
int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My Game");
    window.setFramerateLimit(60);

    sf::RectangleShape rectangle(sf::Vector2f(100,50));
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition({645.f,445.f});
    rectangle.setOutlineThickness(20);
    rectangle.setOutlineColor(sf::Color::Red);

    sf::CircleShape circle({50.f});
    circle.setFillColor(sf::Color::Blue);
    circle.setPosition({375.f, 275.f}); 
    circle.setOutlineThickness(10);
    circle.setOutlineColor(sf::Color::Red );


    sf::RectangleShape box({50.f, 50.f});
    box.setFillColor(sf::Color::Red);
    box.setPosition({375.f, 275.f});

    sf::Clock clock;
    const float speed = 900.f; 

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        float dt = clock.restart().asSeconds();

        sf::Vector2f direction{0.f, 0.f};
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))  direction.x -= 1.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) direction.x += 1.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))    direction.y -= 1.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))  direction.y += 1.f;

        box.move(direction * speed * dt);

        window.clear(sf::Color::Black);
        window.draw(box);
        window.draw(circle);
        window.draw(rectangle);
        window.display();
    }
    cout<<"TRY AGAIN LOSER :)";
    return 0;
}