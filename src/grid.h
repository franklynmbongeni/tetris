#pragma once
#include <vector>
#include <raylib.h>



class Grid
{
    public:
        Grid();
        void initialize();
        void Print();
        //Color GetCellColors();
        void Draw();
        bool IsCellOutside(int row, int);
        int grid [20][10];
    private:
        
        int numRows;
        int numCols;
        int cellSize;  
        std::vector<Color> colors;  
};