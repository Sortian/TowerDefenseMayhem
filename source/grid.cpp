
#include "grid.h"
using namespace std;



Grid::Grid(){
   
    for(int i = 0; i < row_grid_count; i++)
        for(int j = 0; j < column_grid_count; j++)
            grid[i][j] = Vector2D(j * column_size + x_offset,i * row_size + y_offset);

}

void Grid::drawGrid(){

    for(int i = 0; i < row_grid_count; i++){
        for(int j = 0; j < column_grid_count; j++){
            DrawRectangleLines(grid[i][j].x, grid[i][j].y, column_size, row_size, RED);
        }
    }    


}

void Grid::printCordinates(int i, int j){
    cout << "X: " << grid[i][j].x << " Y: " << grid[i][j].y << endl;
}