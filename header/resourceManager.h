#pragma once
#include "utilities.h"
#include <raylib.h>




class ResourceManager{
    TextureNode *  textures;
    int textureCount;
public:
    ResourceManager();
    ~ResourceManager();

    void increaseSize();



    void loadResources();
    Texture2D getResource(const std::string& id);
    void unloadResources();
};
