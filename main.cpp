#include "SFML-2.5.1/include/SFML/Graphics.hpp"
#include "Game.h"
int main()
{

        srand(static_cast<unsigned>(time(NULL)));
    Game game;
    while(game.running()){
        game.update();
        game.render();
    }
   system("pause");
    return 0;
}
// int main()
// {
//     sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//     sf::CircleShape shape(100.f);
//     shape.setFillColor(sf::Color::Green);

//     while (window.isOpen())
//     {
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }

//         window.clear();
//         window.draw(shape);
//         window.display();
//     }

//     return 0;
// }
