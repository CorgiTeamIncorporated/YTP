#include "GameManager.hpp"

GameManager::GameManager(AbstractScene* scene, sf::RenderWindow* window) {
    this->window = window;
    this->scene = scene;
}

void GameManager::start() {
    scene->preload(*window);

    while (window->isOpen()) {
        scene->update(*window);
        scene->render(*window);
    }
}