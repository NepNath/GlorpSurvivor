#include "game.hpp"
#include "src/menu/ui/window.hpp"
#include <SFML/Graphics.hpp>
#include <print>

namespace game::main
{
    int run()
    {
        sf::RenderWindow window(sf::VideoMode(800, 600), "buhh", sf::Style::Default);
        sf::Image icon;

        sf::Texture playerTexture;


        if (!playerTexture.loadFromFile("assets/characterset.png"))
        {
            std::println("Erreur : Impossible de charger characterset.png");
        }

        sf::Sprite playerSprite(playerTexture);
        if (icon.loadFromFile("assets/icon.png"))
        {
            window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
        }
        else
        {
            std::println("Failed to load icon image.");
        }

        window.setFramerateLimit(144);
        window.setVerticalSyncEnabled(true);
        
        while (window.isOpen())
        {
            playerSprite.setTextureRect(sf::IntRect(1, 1, 128, 128));
            sf::Event event;
            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                    case sf::Event::Closed:
                        // Demande de fermeture (croix de fermeture, alt+f4, etc.)
                        window.close();
                        std::println("window has been closed");
                        return 0;

                    case sf::Event::KeyPressed:
                        if (event.key.code == sf::Keyboard::Escape)
                        {
                            window.close();
                            std::println("Escape key pressed, closing window");
                            return 0;
                        }

                        if (event.key.code == sf::Keyboard::Left)
                        {
                            playerSprite.move(-10.0f, 0.0f);
                        }
                        if (event.key.code == sf::Keyboard::Right)
                        {
                            playerSprite.move(10.0f, 0.0f);
                        }
                        if (event.key.code == sf::Keyboard::Up)
                        {
                            playerSprite.move(0.0f, -10.0f);
                        }
                        if (event.key.code == sf::Keyboard::Down)
                        {
                            playerSprite.move(0.0f, 10.0f);
                        }
                }
            }

            window.clear(sf::Color::Black);
            window.draw(playerSprite);
            window.display();
        }
        return 0;
    }
}