#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Jomo Game - Start From Scratch");
    sf::CircleShape player(50.f);
    player.setFillColor(sf::Color::Green);
    player.setPosition(375, 275);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) player.move(-0.2f, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) player.move(0.2f, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) player.move(0, -0.2f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) player.move(0, 0.2f);

        window.clear();
        window.draw(player);
        window.display();
    }
    return 0;
}