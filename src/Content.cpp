#include "Exceptions/LoadException.hpp"
#include "Content.hpp"

// See: Content.hpp.
YDC::Content::Content()
{
}

// See: Content.hpp.
YDC::Content::~Content()
{
    // Delete all the fonts.
    deleteFonts();

    // Delete all the scenes.
    deleteScenes();

    // Delete all the sprites.
    deleteSprites();

    // Delete all the textures.
    deleteTextures();
}

// See: Content.hpp.
void YDC::Content::addFont(const sf::String& name, const sf::String& path)
{
    // Insert a new font instance in the map.
    fonts_.insert({ name, new sf::Font });

    if (!fonts_[name]->loadFromFile(path))
    {
        // Throw the exception.
        throw LoadException(path);
    }
}

// See: Content.hpp.
void YDC::Content::addScene(const sf::String& name, Scene* instance)
{
    // Insert the scene instance in the map.
    scenes_.insert(std::pair<const sf::String, Scene*>(name, instance));
}

// See: Content.hpp.
void YDC::Content::addSprite(const sf::String& name, const sf::String& textureName)
{
    // Insert a new sprite instance in the map.
    sprites_.insert({ name, new sf::Sprite(*textures_[textureName]) });
}

// See: Content.hpp.
void YDC::Content::addTexture(const sf::String& name, const sf::String& path)
{
    // Insert a new texture instance in the map.
    textures_.insert({ name, new sf::Texture });

    if (!textures_[name]->loadFromFile(path))
    {
        // Throw the exception.
        throw LoadException(path);
    }
}

// See: Content.hpp.
void YDC::Content::addTextureAndSprite(const sf::String& name, const sf::String& path)
{
    // Add a new texture.
    addTexture(name, path);

    // Add a new sprite.
    addSprite(name, name);
}

// See: Content.hpp.
void YDC::Content::deleteFonts()
{
    for (auto& font : fonts_)
    {
        // Delete the font instance.
        delete font.second;
    }

    // Clear the fonts map of pointers.
    fonts_.clear();
}

// See: Content.hpp.
void YDC::Content::deleteScenes()
{
    for (auto& scene : scenes_)
    {
        // Delete the scene instance.
        delete scene.second;
    }

    // Clear the scenes map of pointers.
    scenes_.clear();
}

// See: Content.hpp.
void YDC::Content::deleteSprites()
{
    for (auto& sprite : sprites_)
    {
        // Delete the sprite instance.
        delete sprite.second;
    }

    // Clear the sprites map of pointers.
    sprites_.clear();
}

// See: Content.hpp.
void YDC::Content::deleteTextures()
{
    for (auto& texture : textures_)
    {
        // Delete the texture instance.
        delete texture.second;
    }

    // Clear the textures map of pointers.
    textures_.clear();
}

// See: Content.hpp.
YDC::Scene& YDC::Content::getCurrentScene()
{
    // Return the current scene pointer value.
    return *currentScene_;
}

// See: Content.hpp.
sf::Font& YDC::Content::getFont(const sf::String& name)
{
    // Return the font reference.
    return *fonts_[name];
}

// See: Content.hpp.
sf::Font YDC::Content::getFontCopy(const sf::String& name) const
{
    // Return the font copy.
    return *fonts_.at(name);
}

// See: Content.hpp.
YDC::Scene& YDC::Content::getScene(const sf::String& name)
{
    // Return the scene reference..
    return *scenes_[name];
}

// See: Content.hpp.
sf::Sprite& YDC::Content::getSprite(const sf::String& name)
{
    // Return the sprite reference..
    return *sprites_[name];
}

// See: Content.hpp.
sf::Sprite YDC::Content::getSpriteCopy(const sf::String& name) const
{
    // Return the sprite copy.
    return *sprites_.at(name);
}

// See: Content.hpp.
sf::Texture& YDC::Content::getTexture(const sf::String& name)
{
    // Return the texture reference..
    return *textures_[name];
}

// See: Content.hpp.
sf::Texture YDC::Content::getTextureCopy(const sf::String& name) const
{
    // Return the texture copy.
    return *textures_.at(name);
}

// See: Content.hpp.
void YDC::Content::setCurrentScene(Scene& currentScene)
{
    // Set the current scene pointer.
    currentScene_ = &currentScene;
}

// See: Content.hpp.
void YDC::Content::setCurrentScene(const sf::String& name)
{
    // Set the current scene pointer.
    setCurrentScene(*scenes_[name]);
}
