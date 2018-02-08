#ifndef INCOMING_ASSETMANAGER_HPP
#define INCOMING_ASSETMANAGER_HPP

// Map
#include <map>
// String
#include <string>

// graphics
#include <SFML/Graphics.hpp>

// Asset Manager Class
// Handle game resources
class AssetManager
{
    public:

        // Load and create a font
        bool load_font(uint index, std::string _src);

        // Get font
        sf::Font* get_font(uint index);

        // Clear
        void clear();

    private:

        // Fonts array
        std::map<uint, sf::Font*> mFonts;
};

#endif
