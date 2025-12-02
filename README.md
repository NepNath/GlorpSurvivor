# VampireSurvivor-C-Project
School project where the goal is to make a vampire Survivor


## TODO NEXT 

make a loop where every half seconds, the sprite index changes to add animations

suggestion de clanker : 

```
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
        // On définit le rectangle une seule fois au début, pas dans la boucle
        playerSprite.setTextureRect(sf::IntRect(1, 1, 128, 128)); 

        if (icon.loadFromFile("assets/icon.png"))
        {
            window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
        }

        // V-Sync activée
        window.setVerticalSyncEnabled(true);
        // Note: setFramerateLimit est souvent redondant si VSync est true, mais on peut le garder
        window.setFramerateLimit(144); 

        // --- 1. Initialisation de l'horloge et de la vitesse ---
        sf::Clock clock;
        float speed = 300.0f; // Vitesse en pixels par seconde

        while (window.isOpen())
        {
            // --- 2. Calcul du Delta Time (Temps écoulé depuis la dernière frame) ---
            sf::Time dtTime = clock.restart();
            float dt = dtTime.asSeconds(); // ex: 0.016 pour 60 FPS

            sf::Event event;
            while (window.pollEvent(event))
            {
                // Ici, on ne gère que les événements "uniques" (fermeture, touche pressée une seule fois)
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                    return 0;
                }
                
                // Pour quitter avec Echap (c'est un événement unique, donc ça reste ici)
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                    return 0;
                }
            }

            // --- 3. Gestion des mouvements fluides (Hors du pollEvent) ---
            sf::Vector2f movement(0.0f, 0.0f);

            // On vérifie l'ÉTAT de la touche (est-elle enfoncée maintenant ?)
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                movement.x -= 1.0f;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                movement.x += 1.0f;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                movement.y -= 1.0f;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                movement.y += 1.0f;
            }

            // --- 4. Application du mouvement avec Delta Time ---
            // Formule : Direction * Vitesse * Temps
            // Si on ne bouge pas, movement est à 0, donc rien ne se passe.
            playerSprite.move(movement * speed * dt);

            window.clear(sf::Color::Black);
            window.draw(playerSprite);
            window.display();
        }
        return 0;
    }
}
```