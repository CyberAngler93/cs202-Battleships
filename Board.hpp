#ifndef board_HPP
#define board_HPP
#include<vector>
class Board
{
public:
    Board();
    void shot(char y,int x, bool isHit);
    int get(char y,int x);
    void print();
private:
    std::vector<std::vector<int>> board;
    int toInt(char c);
};
// 0 = no interaction
// 1 = miss
// 2 = hit
#endif
