#include <SFML/Graphics.hpp>
#include <vector>
#include<ctime>
class Game {
    private:
    //pass window as pointer
        sf::RenderWindow *window;
        //pass videoMode
        sf::VideoMode videoMode;
        //get events
        sf::Event ev;

        std::vector<sf::RectangleShape> enemies; 
        sf::RectangleShape enemy;
        sf::Vector2i mousePos;
        sf::Vector2f mousePosView;
        sf::Font font;
        sf::Text uiText;
        //game logic
        unsigned points;
        float enemySpawnTimer;
        float enemySpawnTimerMax;
        int maxEnemies;
        bool mouseHeld;
        int health;
        bool endGame;


        //declare initialize veriables
        void initVeriable();
        //declare init window
        void initWindow();


        void initEnemy();
        void initFont();
        void initText();
    public:
        //construction
        Game();
        //deconstruct
        virtual ~Game();
        //check if the window is running
        const bool running() const;
        void spawnEnemy();
        void updateEnemies();
        void updateText();
        void updateMousePos();
        void renderEnemies();
        void renderText();
        void pollEvents();
        void update();
        void render();
};