#include "board.hpp"
#include <iostream>
Board::Board()
{
    board = std::vector<std::vector<int>>(10,std::vector<int>(10));
}
void Board::print()
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            std::cout<<board[j][i];
        }
        std::cout<<std::endl;
    }
}
void Board::shot(char y,int x, bool isHit)
{
    if(board[x][toInt(y)]==0)
    {
        if(isHit)
            board[x][toInt(y)]=2;
        else
            board[x][toInt(y)]=1;
    }
    else
        std::cout<<"Error in Board::shot(): location is already hit("<<y<<","<<x<<")"<<std::endl;
}
int Board::get(char y, int x)
{
    return board[x][toInt(y)];
}
int Board::toInt(char c)
{
    int rtn=c-97;
    return rtn;
}
