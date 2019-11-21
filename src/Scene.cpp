#include "Scene.hpp"

// See: Scene.hpp.
YDC::Scene::Scene(Content& content) :
    content_(content)
{
}

// See: Scene.hpp.
YDC::Scene::~Scene()
{
}

// See: Scene.hpp.
void YDC::Scene::run(sf::RenderWindow& window)
{
    // Run the function pointed to by the current act.
    (this->*currentAct_)(window);
}

// See: Scene.hpp.
void YDC::Scene::setCurrentAct(Act pointer)
{
    // Set the current act pointer.
    currentAct_ = pointer;
}
