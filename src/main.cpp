#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
    sf::CircleShape shape(100.f);

    sf::Texture charSprite;
    if(!charSprite.loadFromFile("res/fox.png")){
        return -1;
    };
    
    shape.setFillColor(sf::Color::Red);

    sf::Sprite character;
    character.setTexture(charSprite);
    character.setScale(5,5);
    character.setOrigin(8,8);
    character.setPosition(1280/2,720/2);

    // Main game Loop
    while (window.isOpen())
    {

        // ----------UPDATE----------
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Periksa event Close
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Periksa tombol Escape
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
        // ----------UPDATE----------
        // ----------RENDER------------
        window.clear();
        window.draw(character);
        window.display();
        // ----------RENDER------------
        
    }

    return 0;
}