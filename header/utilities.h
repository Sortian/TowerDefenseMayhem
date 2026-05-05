#pragma once
class Vector2D
{
public:
    float x;
    float y;

    Vector2D() : x(0.0f) , y(0.0f){}

    Vector2D(float a, float b) : x(a), y(b){}
    Vector2D(int a, int b) : x((float)a), y((float)b){}
    
    Vector2D& operator=(Vector2D&& other){
        x = other.x;
        y = other.y;

        return *this;

    }
};
