#include "tower.h"
#include "resourceManager.h"
void CannonTower::targetEnemy() {

};
void CannonTower::draw(ResourceManager &rb) {

    Texture2D texture = rb.getResource("cannon");
    Vector2 position = {getPos().x, getPos().y};

    DrawTextureEx(texture, position, 0.0f, 1.0f, WHITE);


};
void CannonTower ::update() {

};



void SniperTower::targetEnemy() {

};
void SniperTower::draw(ResourceManager &rb) {

    
};
void SniperTower ::update() {

};


void MachineGunTower::targetEnemy() {

};
void MachineGunTower::draw(ResourceManager &rb) {


    
};
void MachineGunTower ::update() {

};


void SlowTower::targetEnemy() {

};
void SlowTower::draw(ResourceManager &rb) {


    
};
void SlowTower ::update() {

};