
#include "grid.h"
using namespace std;

Grid::Grid()
{

    for (int i = 0; i < row_grid_count; i++)
        for (int j = 0; j < cols_grid_count; j++)
            grid[i][j] = Vector2D(j * cols_size + x_offset, i * row_size + y_offset);

    for (int i = 0; i < row_grid_count; i++)
        for (int j = 0; j < cols_grid_count; j++)
            available[i][j] = true;
}

void Grid::drawGrid()
{

    for (int i = 0; i < row_grid_count; i++)
    {
        for (int j = 0; j < cols_grid_count; j++)
        {
            DrawRectangleLines(grid[i][j].x, grid[i][j].y, cols_size, row_size, RED);
        }
    }
}

void Grid::printCordinates(int i, int j)
{
    cout << "X: " << grid[i][j].x << " Y: " << grid[i][j].y << endl;
}


Vector2D Grid::returnCell(float x, float y)
{
    Vector2D res;

    if (x < 100 || y < 50 || x > 1250 || y > 650)
        return {-1, -1};

    float localX = x-x_offset;
    float localY = y-y_offset;

    int col = localX/cols_size;
    int row = localY/row_size;

    res = {col,row};

    


    return res;
}

Vector2D Grid::getCordinates(int x, int y){

    Vector2D result;

    result.x = x * cols_size + x_offset;
    result.y = y * row_size + y_offset;

    return result;
}