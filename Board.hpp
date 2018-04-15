#ifndef Board_HPP
#define Board_HPP

#include<Vector>

class Board
{
public:
    Board();
    void shot(char y,int x, bool isHit);
    int get(char y,int x);
    void print();
private:
    int board[10][10];
    int toInt(char c);
};
// 0 = no interaction
// 1 = miss
// 2 = hit



#endif
