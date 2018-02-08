#include "AssetManager.hpp"

using namespace std;

typedef std::map<uint, sf::Font*>::iterator MFONT_IT;

// Load and create a font
bool AssetManager::load_font(uint index, std::string _src)
{
    mFonts[index] = new sf::Font;
    return mFonts[index]->loadFromFile(_src);
}

// Get font
sf::Font* AssetManager::get_font(uint index)
{
    MFONT_IT font_map;
    if((font_map = mFonts.find(index)) != mFonts.end())
        return font_map->second;
    return new sf::Font;
}

// Clear
void AssetManager::clear()
{
    for (size_t i = 0; i < mFonts.size(); i++)
        delete mFonts[i];
    mFonts.clear();
}
