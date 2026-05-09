#pragma once
#include <iostream>
#include <raylib.h>
#include "utilities.h"

class Grid
{
private:
    static const int x_offset = 100;
    static const int y_offset = 50;
    static const int row_grid_count = 10;
    static const int column_grid_count = 15;
    static const int total_width = 1150;
    static const int total_height = 600;
    static const int row_size = total_height / row_grid_count;
    static const int column_size = total_width / column_grid_count;
    Vector2D grid[row_grid_count][column_grid_count];

public:
    Grid();
    void printCordinates(int i, int j);
    void drawGrid();
};