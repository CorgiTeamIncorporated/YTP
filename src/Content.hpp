#ifndef YDC_CONTENT_HPP_
#define YDC_CONTENT_HPP_

#include <map>
#include <SFML/Graphics.hpp>
#include "Scene.hpp"

namespace YDC
{
    /// Game content (audio, fonts, sprites, etc).
    class Content
    {
    public:
        /// Constructs a new content instance.
        Content();

        /// Destructs the content instance.
        ~Content();

        /// Loads and adds a new font.
        ///
        /// @param name The unique name of the font, is used to call it.
        /// @param path The path to the font.
        void addFont(const sf::String& name, const sf::String& path);

        /// Loads and adds a new scene.
        ///
        /// @param name The unique name of the scene, is used to call it.
        /// @param instance The pointer to the instance of the scene.
        void addScene(const sf::String& name, Scene* instance);

        /// Loads and adds a new sprite.
        ///
        /// @param name The unique name of the sprite, is used to call it.
        /// @param textureName The name of the texture to bind the sprite to.
        void addSprite(const sf::String& name, const sf::String& textureName);

        /// Loads and adds a new texture.
        ///
        /// @param name The unique name of the texture, is used to call it.
        /// @param path The path to the texture.
        void addTexture(const sf::String& name, const sf::String& path);

        /// Gets the current scene.
        ///
        /// @return scene The current scene.
        Scene& getCurrentScene();

        /// Gets the pointer to the font.
        ///
        /// @param name The name of the font.
        ///
        /// @return The font pointer.
        sf::Font& getFont(const sf::String& name);

        /// Gets the copy of the font.
        ///
        /// @param name The name of the font.
        ///
        /// @return The font copy.
        sf::Font getFontCopy(const sf::String& name);

        /// Gets the pointer to the scene.
        ///
        /// @param name The name of the scene.
        ///
        /// @return The scene pointer.
        Scene& getScene(const sf::String& name);

        /// Gets the pointer to the sprite.
        ///
        /// @param name The name of the sprite.
        ///
        /// @return The sprite pointer.
        sf::Sprite& getSprite(const sf::String& name);

        /// Gets the copy of the sprite.
        ///
        /// @param name The name of the sprite.
        ///
        /// @return The sprite copy.
        sf::Sprite getSpriteCopy(const sf::String& name);

        /// Gets the pointer to the texture.
        ///
        /// @param name The name of the texture.
        ///
        /// @return The texture pointer.
        sf::Texture& getTexture(const sf::String& name);

        /// Gets the copy of the texture.
        ///
        /// @param name The name of the texture.
        ///
        /// @return The texture copy.
        sf::Texture getTextureCopy(const sf::String& name);

        /// Sets the current scene.
        ///
        /// @param scene The scene reference.
        void setCurrentScene(Scene& scene);

        /// Sets the current scene.
        ///
        /// @param name The name of the scene.
        void setCurrentScene(const sf::String& name);

    private:
        /// The current scene to show.
        Scene* currentScene_;

        /// The fonts map.
        std::map<const sf::String, sf::Font*> fonts_;

        /// The scenes map.
        std::map<const sf::String, Scene*> scenes_;

        /// The sprites map.
        std::map<const sf::String, sf::Sprite*> sprites_;

        /// The textures map (for keeping sprite textures).
        std::map<const sf::String, sf::Texture*> textures_;

        /// Deletes all the fonts.
        void deleteFonts();

        /// Deletes all the scenes.
        void deleteScenes();

        /// Deletes all the sprites.
        void deleteSprites();

        /// Deletes all the textures.
        void deleteTextures();
    };
} // YDC

#endif // YDC_CONTENT_HPP_
