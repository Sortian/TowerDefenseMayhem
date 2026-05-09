#include "resourceManager.h"

ResourceManager::ResourceManager() {
    textureCount = 7;
    textures = new TextureNode[textureCount];
}

ResourceManager::~ResourceManager() {
    delete[] textures;
}

void ResourceManager::loadResources() {
    for (int i = 1; i < textureCount-2; i++) {
        textures[i].texture = LoadTexture(("assets/enemy_" + std::to_string(i) + ".png").c_str());
        textures[i].name = "enemy_" + std::to_string(i);
        cout << textures[i].name << " loaded successfully." << endl;
    }

    textures[5].texture = LoadTexture(("assets/bg_1.png"));
    textures[5].name = "bg_1";
    textures[6].texture = LoadTexture(("assets/shadow.png"));
    textures[6].name = "shadow";

}

void ResourceManager::unloadResources() {
    for (int i = 0; i < textureCount; i++) {
        UnloadTexture(textures[i].texture);
    }
}

Texture2D ResourceManager::getResource(const std::string& id) {
    
    for (int i = 0; i < textureCount; i++) {
        if (textures[i].name == id) {
            
            return textures[i].texture;
        }
    }
    return Texture2D(); 
}

void ResourceManager::increaseSize() {
    TextureNode* newTextures = new TextureNode[textureCount + 10];
    for (int i = 0; i < textureCount; i++) {
        newTextures[i] = textures[i];
    }
    delete[] textures;
    textures = newTextures;
    textureCount += 10;
}
