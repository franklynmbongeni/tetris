#include "game.h"
#include <random>

Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    Gameover = false;
}

Block Game::GetRandomBlock()
{
    if(blocks.empty())
    {
        blocks = GetAllBlocks();
    }
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

std::vector<Block> Game::GetAllBlocks()
{
    return {LBlock(), JBlock(), IBlock(), OBlock(), SBlock(), ZBlock(), TBlock()};
}

void Game::Draw()
{
    grid.Draw();
    currentBlock.Draw();
}

bool Game::IsBlockOutside()
{
   std::vector<Position> tiles = currentBlock.GetCellPosition();
   for(Position item : tiles)
   {
    if(grid.IsCellOutside(item.row, item.column))
    {
        return true;
    }
   }
   return false;
}

void Game::HandleInput()
{
    int keyPressed = GetKeyPressed();
    if(Gameover && keyPressed != 0)
    {
        Gameover = false;
        Reset();
    }
    switch(keyPressed)
    {
        case KEY_LEFT:
             MoveBlockLeft();
             break;
        case KEY_RIGHT:
            MoveBlockRight();
            break;
        case KEY_DOWN:
            MoveBlockDown();
            break;  
        case KEY_UP:
            RotateBlock();
            break;

    }
}

void Game::MoveBlockLeft()
{
    if(!Gameover)
    { 
        currentBlock.Move(0, -1);
        if (IsBlockOutside() || BlockFits() == false)
        {
        currentBlock.Move(0, 1);
        }
    }
}

void Game::MoveBlockRight()
{
    if(!Gameover)
    { 
        currentBlock.Move(0, 1);
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock.Move(0, -1);
        }
    }
}

void Game::MoveBlockDown()
{
    if(!Gameover)
    {

        currentBlock.Move(1, 0);
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock.Move(-1, 0);
            LockBlock();
        }
    }
}

void Game::RotateBlock()
{
    if(!Gameover)
    {
        currentBlock.Rotate();
        if(IsBlockOutside() || BlockFits() == false)/////odidkd
        {
            currentBlock.UndoRotation();
        }
    }
}

void Game::LockBlock()
{
    std::vector<Position> tiles = currentBlock.GetCellPosition();
    for(Position item: tiles)
    {
        grid.grid[item.row][item.column] = currentBlock.id;
    }
    currentBlock = nextBlock;
    if(BlockFits() == false)
    {
        Gameover = true;
    }
    nextBlock = GetRandomBlock();
    //int rowsCleared = grid.ClearFullRows(); 
    grid.ClearFullRows();
}

bool Game::BlockFits()
{
    std::vector<Position> tiles = currentBlock.GetCellPosition();
    for(Position item : tiles)
    {
        if(grid.IsCellEmpty(item.row,item.column) == false)
        {
            return false;
        }

    }
    return true;
}

void Game::Reset()
{
    grid.initialize();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
}
