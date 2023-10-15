#include "Grid.h"

Grid getGrid(short size = 4);

int main()
{
    Grid grid(5);
    Grid grid2 = std::move(grid);//move constructor call via transformation lvalue -> rvalue by function std::move;

    Grid grid3;
    grid3 = std::move(grid2);//move operator call  via transformation lvalue -> rvalue by function std::move;

    Grid grid2_2 = getGrid(6);//move constructor call

    Grid grid3_2;
    grid3_2 = getGrid(3);//move operator call

    if (grid == true)
        std::cout << "\nGrid is empty\n";
    else
        std::cout << "\nGrid is filled\n";

    if (grid2_2 == grid3)
        std::cout << "\nGrids are equal\n";
    else
        std::cout << "\nGrid are not equal\n";

    return 0;
}
;
Grid getGrid(short size) {
    return Grid(size);
}
;
