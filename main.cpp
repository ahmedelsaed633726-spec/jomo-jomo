#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Jomo Game - Movement Test");

    sf::CircleShape player(50.f);
    player.setFillColor(sf::Color::Green);
    player.setPosition(375, 275);

    float speed = 0.5f; // سرعة حركة لوفي

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // تحريك الدائرة بالأسهم
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) player.move(-speed, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) player.move(speed, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) player.move(0, -speed);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) player.move(0, speed);

        window.clear();
        window.draw(player);
        window.display();
    }
    return 0;
}