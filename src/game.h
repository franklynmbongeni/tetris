#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game
{
    public:
        Game();
        Block GetRandomBlock();
        std::vector<Block> GetAllBlocks();
        Grid grid;
        void HandleInput();
        void MoveBlockLeft();
        void MoveBlockRight();
        void MoveBlockDown();
        void Draw();
        bool Gameover;

    private:  
        bool IsBlockOutside(); 
        void RotateBlock();
        void LockBlock();
        void Reset();
        bool BlockFits(); 
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
};