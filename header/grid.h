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
    static const int cols_grid_count = 15;
    static const int total_width = 1150;
    static const int total_height = 600;

    Rectangle gridRect = {100.0f, 50.0f, 1150.0f, 600.0f};

    static const int row_size = total_height / row_grid_count;
    static const int cols_size = total_width / cols_grid_count;
    Vector2D grid[row_grid_count][cols_grid_count];
    bool available[row_grid_count][cols_grid_count];

public:
    Grid();
    void printCordinates(int i, int j);
    void drawGrid();

    
    

    Rectangle getgridRect()
    {
        return gridRect;
    }

    Vector2D getCordinates(int i, int j);
    Vector2D returnCell(float x, float y);
};