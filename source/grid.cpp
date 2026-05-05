
#include "grid.h"
using namespace std;



Grid::Grid(){
    total_width = 1360;
    total_height = 760;

    row_size = total_width / grid_size;
    collumn_size = total_height / grid_size;

    for(int i = 0; i < grid_size; i++)
        for(int j = 0; j < grid_size; j++)
            grid[i][j] = Vector2D(i*row_size,j*collumn_size);
    

}

void Grid::drawGrid(){

    for(int i = 0; i < grid_size; i++){
        for(int j = 0; j < grid_size; j++){
            DrawRectangleLines(grid[i][j].x, grid[i][j].y, row_size, collumn_size, RED);
        }
    }    


}

void Grid::printCordinates(int i, int j){
    cout << "X: " << grid[i][j].x << " Y: " << grid[i][j].y << endl;
}