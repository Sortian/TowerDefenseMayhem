#include "enemy.h"
#include "resourceManager.h"



void BasicEnemy::draw(ResourceManager &rb)
{
    Texture2D texture = rb.getResource("enemy_1");
    Vector2 position = {getPos().x, getPos().y};

    DrawTextureEx(texture, position, 0.0f, 0.3f, WHITE);
}

void BasicEnemy::update()
{

    Vector2D pos = getPos();
    Vector2D direction = getDirection();

    
    int t = getTurn();

    if (pos.x > 490 && t == 1)
    {
        setDirection(0,1);
        setTurn(++t);
    }
    else if (pos.y > 560 && t == 2)
    {
        setDirection(1,0);
        setTurn(++t);
    }
    else if (pos.x > 968 && t == 3)
    {
        setDirection(0, -1);
        setTurn(++t);
    }
    else if (pos.y < 250 && t == 4)
    {
        setDirection(1, 0);
        setTurn(++t);
    }

    if (direction.x == 1)
        pos.x += getSpeed();

    if (direction.y)
        pos.y += getSpeed() * direction.y;

    setPos(pos);

}

void FastEnemy::draw(ResourceManager &rb)
{

    Texture2D texture = rb.getResource("enemy_2");
    Vector2 position = {getPos().x, getPos().y};

    DrawTextureEx(texture, position, 0.0f, 0.2f, WHITE);
}

void FastEnemy::update()
{

    Vector2D pos = getPos();

    Vector2D direction = getDirection();

    int t = getTurn();

    if (pos.x > 500 && t == 1)
    {
        setDirection(0,1);
        setTurn(++t);
    }
    else if (pos.y > 590 && t == 2)
    {
        setDirection(1,0);
        setTurn(++t);
    }
    else if (pos.x > 968 && t == 3)
    {
        setDirection(0, -1);
        setTurn(++t);
    }
    else if (pos.y < 280 && t == 4)
    {
        setDirection(1, 0);
        setTurn(++t);
    }

    if (direction.x == 1)
        pos.x += getSpeed();

    if (direction.y)
        pos.y += getSpeed() * direction.y;

    setPos(pos);
}

void TankEnemy::draw(ResourceManager &rb)
{

    Texture2D texture = rb.getResource("enemy_4");
    Vector2 position = {getPos().x, getPos().y};

    DrawTextureEx(texture, position, 0.0f, 0.5f, WHITE);
}

void TankEnemy::update()
{

    Vector2D pos = getPos();

    Vector2D direction = getDirection();

    
    int t = getTurn();

    if (pos.x > 490 && t == 1)
    {
        setDirection(0,1);
        setTurn(++t);
    }
    else if (pos.y > 560 && t == 2)
    {
        setDirection(1,0);
        setTurn(++t);
    }
    else if (pos.x > 968 && t == 3)
    {
        setDirection(0, -1);
        setTurn(++t);
    }
    else if (pos.y < 250 && t == 4)
    {
        setDirection(1, 0);
        setTurn(++t);
    }

    if (direction.x == 1)
        pos.x += getSpeed();

    if (direction.y)
        pos.y += getSpeed() * direction.y;

    setPos(pos);
}



void FlyEnemy::draw(ResourceManager &rb)
{

    Texture2D texture = rb.getResource("enemy_3");
    Vector2 position = {getPos().x, getPos().y};

    Texture2D shadowTexture = rb.getResource("shadow");
    Vector2 shadowpos = {position.x-80, position.y -25};

    DrawTextureEx(texture,position, 0.0f, 0.3f, WHITE);
    DrawTextureEx(shadowTexture,shadowpos,0.0f,2.0f,WHITE);
}

void FlyEnemy::update()
{

    Vector2D pos = getPos();

    Vector2D direction = getDirection();

    int t = getTurn();

    if (pos.x > 490 && t == 1)
    {
        setDirection(0,1);
        setTurn(++t);
    }
    else if (pos.y > 560 && t == 2)
    {
        setDirection(1,0);
        setTurn(++t);
    }
    else if (pos.x > 968 && t == 3)
    {
        setDirection(0, -1);
        setTurn(++t);
    }
    else if (pos.y < 250 && t == 4)
    {
        setDirection(1, 0);
        setTurn(++t);
    }

    if (direction.x == 1)
        pos.x += getSpeed();

    if (direction.y)
        pos.y += getSpeed() * direction.y;

    setPos(pos);
}
