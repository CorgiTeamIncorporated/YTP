#include "Scenes/AbstractScene.hpp"
#include <string>

class RegistrationSuggest: public AbstractScene {
private:
    void start_game(sf::RenderWindow& window, bool offline_mode, std::string token = "DEADBEEF");
    std::string login_token = "DEADBEEF";
    bool check_if_logged();

    sf::RectangleShape offline_button;
    sf::RectangleShape online_button;

    sf::Font font; 
    sf::Text offline_text;
    sf::Text online_text;
public:
    void preload(sf::RenderWindow& window);
    void update(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    void setup(sf::RenderWindow& window);
    void generate_token();
};