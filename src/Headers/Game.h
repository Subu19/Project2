#include <SFML/Graphics.hpp>

class Game {
    private:
    //pass window as pointer
        sf::RenderWindow *window;
        //pass videoMode
        sf::VideoMode videoMode;
        //get events
        sf::Event ev;
        //declare initialize veriables
        void initVeriable();
        //declare init window
        void initWindow();
    public:
        //construction
        Game();
        //deconstruct
        virtual ~Game();
        //check if the window is running
        const bool running() const;
        
        void pollEvents();
        void update();
        void render();
};