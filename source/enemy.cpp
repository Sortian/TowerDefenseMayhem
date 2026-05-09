#include "enemy.h"
#include "resourceManager.h"

Enemy::Enemy() {
    speed = 1.0f;
    health = 100;
    damage = 10;
}


void Enemy::update(){
    Vector2D pos = getPos();
    pos.x += getSpeed();
    setPos(pos);
}

void Enemy::draw(ResourceManager& rb){
    Texture2D texture = rb.getResource("enemy");
    DrawTexture(texture, getPos().x, getPos().y, WHITE);

}

void FastEnemy::draw(ResourceManager& rb){
    
    Texture2D texture = rb.getResource("enemy_1");
    Vector2 position = { getPos().x, getPos().y };

    DrawTextureEx(texture, position, 0.0f, 0.2f, WHITE);

}
