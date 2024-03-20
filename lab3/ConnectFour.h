#ifndef __CONNECTFOUR_H__
#define __CONNECTFOUR_H__

#include <cstring>
#include <iostream>

using namespace std;

enum Grid {
    Empty,
    PlayerA,
    PlayerB,
};

enum Status {
    Playing,
    Draw,
    PlayerAWin,
    PlayerBWin,
};

class ConnectFour {
   private:
    Grid m_board[6][7];
    Status game_status = Playing;
    int m_board_c[7];

   public:
    ConnectFour();

    void Place(int step, int column);
    Status GetGameStatus();
    void PrintBoard();
    void PrintWinner();
};

#endif  // __CONNECTFOUR_H__