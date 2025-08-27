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
        bool IsCellEmpty(int row, int column);
        int grid [20][10];
        int ClearFullRows();
    private:
        
        int numRows;
        int numCols;
        int cellSize;  
        bool IsRowFull(int row);
        void ClearRaw(int row);
        void MoveRowDown(int row, int numRows);
        std::vector<Color> colors;  
};