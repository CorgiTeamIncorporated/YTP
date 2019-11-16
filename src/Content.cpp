#include "Exceptions/LoadException.hpp"
#include "Content.hpp"

YDC::Content::Content()
{
}

YDC::Content::~Content()
{
    deleteFonts();
    deleteScenes();
    deleteSprites();
    deleteTextures();
}

void YDC::Content::addFont(const sf::String& name, const sf::String& path)
{
    fonts_.insert({ name, new sf::Font });
    if (!fonts_[name]->loadFromFile(path))
    {
        throw LoadException(path);
    }
}

void YDC::Content::addScene(const sf::String& name, Scene* instance)
{
    scenes_.insert(std::pair<const sf::String, Scene*>(name, instance));
}

void YDC::Content::addSprite(const sf::String& name, const sf::String& textureName)
{
    sprites_.insert({ name, new sf::Sprite(*textures_[textureName]) });
}

void YDC::Content::addTexture(const sf::String& name, const sf::String& path)
{
    textures_.insert({ name, new sf::Texture });
    if (!textures_[name]->loadFromFile(path))
    {
        throw LoadException(path);
    }
}

void YDC::Content::deleteFonts()
{
    for (auto& font : fonts_)
    {
        delete font.second;
    }
    fonts_.clear();
}

void YDC::Content::deleteScenes()
{
    for (auto& scene : scenes_)
    {
        delete scene.second;
    }
    scenes_.clear();
}

void YDC::Content::deleteSprites()
{
    for (auto& sprite : sprites_)
    {
        delete sprite.second;
    }
    sprites_.clear();
}

void YDC::Content::deleteTextures()
{
    for (auto& texture : textures_)
    {
        delete texture.second;
    }
    textures_.clear();
}

YDC::Scene& YDC::Content::getCurrentScene()
{
    return *currentScene_;
}

sf::Font& YDC::Content::getFont(const sf::String& name)
{
    return *fonts_[name];
}

sf::Font YDC::Content::getFontCopy(const sf::String& name)
{
    return *fonts_[name];
}

YDC::Scene& YDC::Content::getScene(const sf::String& name)
{
    return *scenes_[name];
}

sf::Sprite& YDC::Content::getSprite(const sf::String& name)
{
    return *sprites_[name];
}

sf::Sprite YDC::Content::getSpriteCopy(const sf::String& name)
{
    return *sprites_[name];
}

sf::Texture& YDC::Content::getTexture(const sf::String& name)
{
    return *textures_[name];
}

sf::Texture YDC::Content::getTextureCopy(const sf::String& name)
{
    return *textures_[name];
}

void YDC::Content::setCurrentScene(Scene& currentScene)
{
    currentScene_ = &currentScene;
}

void YDC::Content::setCurrentScene(const sf::String& name)
{
    setCurrentScene(*scenes_[name]);
}
