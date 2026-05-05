#pragma once
#include<iostream>
#include <raylib.h>
#include "utilities.h"

const int grid_size = 40;


class Grid
{
private:
    int total_width;
    int total_height;
    int row_size;
    int collumn_size;
    Vector2D grid[grid_size][grid_size];

public:
    Grid();
    void printCordinates(int i, int j);
    void drawGrid();
};