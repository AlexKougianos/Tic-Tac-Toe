#ifndef _GAMEBOARD_HPP_
#define _GAMEBOARD_HPP_

#include <iostream>

class GameBoard
{
    private:
        char board[9];
        char turn;

    public:
        GameBoard();

        void gamePlay();
        void initialPrint();
        void printBoard();
        bool checkWinningCondition();
        void pressKeyToContinue();
	    void lastPrint();
};

#endif
