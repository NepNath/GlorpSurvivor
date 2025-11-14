#include <SFML/Graphics.hpp>
#include <print>



int main()
{

    int windowWidth = 800, windowHeight = 600;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML Window", sf::Style::Default);

    while (window.isOpen())
    {
        // gestion d'événements
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Demande de fermeture (croix de fermeture, alt+f4, etc.)
            if (event.type == sf::Event::Closed)
            {
                window.close();
                std::println("window has been closed");
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
                std::println("Escape key pressed, closing window");
            }
            //d'autre évènements peuvent être gérés ici
        }

        // Effacement de l'ancienne frame (framebuffer)
        window.clear(sf::Color::Black);
        // ... Ici on dessine les objets, sprites, textes, formes, etc. ...


        window.display(); // Affichage de la nouvelle frame
    }

    return 0;
}
