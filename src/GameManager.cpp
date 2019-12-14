#include "GameManager.hpp"

GameManager::GameManager(AbstractScene* scene, sf::RenderWindow* window) {
    scene->manager = this;
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

void GameManager::set_scene(AbstractScene* scene) {
    this->scene = scene;
    scene->manager = this;
    scene->preload(*window);
}