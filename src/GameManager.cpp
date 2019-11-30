#include "GameManager.hpp"

GameManager::GameManager(AbstractScene* scene, sf::RenderWindow* window) {
    this->window = window;
    this->scene = scene;
}

void GameManager::set_scene(AbstractScene* scene) {
    this->scene = scene;
}

void GameManager::start() {
    sf::Event event;
    scene->preload();

    while (window->isOpen()) {
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
                continue;
            }
            scene->handle_event(event, *window);
        }
        scene->update(*window);
        window->clear();
        scene->render(*window);
        window->display();
    }
}
