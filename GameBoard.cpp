#include "GameBoard.hpp"
// #include <cstdlib>

using namespace std;

GameBoard::GameBoard()
{
    for (int i = 1; i <= 9; i++)
    {
        board[i - 1] = ' ';
    }
    turn = 'X';
}

void GameBoard::gamePlay()
{
    cout << endl << "---> Type 1 - 9 to place your markers. (Press enter to continue) <---" << endl << endl << endl;
    initialPrint();
    cin.ignore();

    int index;

    do {
        printBoard();

        cin >> index;

        while (board[index - 1] != ' ' || index < 1 || index > 9)
        {
            cout << endl << "Wrong input. Try again!" << endl;
            cin >> index;
        }

        board[index - 1] = turn;
        cout << board[0];

        if (turn == 'X')
            turn = 'O';
        else
            turn = 'X';

    } while(!checkWinningCondition());

    cout << endl;
}

void GameBoard::printBoard()
{
    system("CLS");
    cout << endl << " Player 1 (X) - Player 2 (O)" << endl << endl
         << "       " << "|" << "     " << "|" << endl
         << "    " << board[0] << "  |  "<< board[1] << "  |  " << board[2] << endl
         << "  _____" << "|" << "_____" << "|" << "_____" << endl
         << "       " << "|" << "     " << "|" << endl
         << "    " << board[3] << "  |  "<< board[4] << "  |  " << board[5] << endl
         << "  _____" << "|" << "_____" << "|" << "_____" << endl
         << "       " << "|" << "     " << "|" << endl
         << "    " << board[6] << "  |  "<< board[7] << "  |  " << board[8] << endl
         << "       " << "|" << "     " << "|" << endl << endl;

    if (turn == 'X')
        cout << "Player 1, place your marker." << endl;
    else
        cout << "Player 2, place your marker." << endl;
}

void GameBoard::initialPrint()
{
    cout << "       " << "|" << "     " << "|" << endl
     << "    " << 1 << "  |  "<< 2 << "  |  " << 3 << endl
     << "  _____" << "|" << "_____" << "|" << "_____" << endl
     << "       " << "|" << "     " << "|" << endl
     << "    " << 4 << "  |  "<< 5 << "  |  " << 6 << endl
     << "  _____" << "|" << "_____" << "|" << "_____" << endl
     << "       " << "|" << "     " << "|" << endl
     << "    " << 7 << "  |  "<< 8 << "  |  " << 9 << endl
     << "       " << "|" << "     " << "|" << endl << endl;
}

bool GameBoard::checkWinningCondition()
{
    char winner = '0';
    if (board[0] == board[1] && board[0] == board[2] && (board[0] == 'X' || board[0] == 'O'))
        winner = board[0];

    else if (board[3] == board[4] && board[3] == board[5] && (board[3] == 'X' || board[3] == 'O'))
        winner = board[3];

    else if (board[6] == board[7] && board[6] == board[8] && (board[6] == 'X' || board[6] == 'O'))
        winner = board[6];

    else if (board[0] == board[3] && board[0] == board[6] && (board[0] == 'X' || board[0] == 'O'))
        winner = board[0];

    else if (board[1] == board[4] && board[1] == board[7] && (board[1] == 'X' || board[1] == 'O'))
        winner = board[1];

    else if (board[2] == board[5] && board[2] == board[8] && (board[2] == 'X' || board[2] == 'O'))
        winner = board[2];

    else if (board[0] == board[4] && board[0] == board[8] && (board[0] == 'X' || board[0] == 'O'))
        winner = board[0];

    else if (board[2] == board[4] && board[2] == board[6] && (board[2] == 'X' || board[2] == 'O'))
        winner = board[6];

    if (winner == '0')
    {
	    for (int i = 0; i < 9; i++)
        {
            if (board[i] == ' ')
                    return false;

                if (i = 8)
            {
                    cout << "It's a tie!" << endl;
                lastPrint();
            }

            return false;
	    }
    }


    if (winner == 'X')
    {
        system("CLS");
        cout << endl << endl << "Player 1 is the winner !" << endl << endl;
        lastPrint();
        cin.ignore();
        cin.ignore();

        return true;
    }
    else
    {
        system("CLS");
        cout << endl << endl <<  "Player 2 is the winner !" << endl << endl;
        lastPrint();
        cin.ignore();
        cin.ignore();
        
        return true;
    }
}

void GameBoard::pressKeyToContinue()
{
    char ch;
    cin >> ch;

    if (ch)
        return;
}

void GameBoard::lastPrint()
{
     cout << endl << " Player 1 (X) - Player 2 (O)" << endl << endl
          << "       " << "|" << "     " << "|" << endl
          << "    " << board[0] << "  |  "<< board[1] << "  |  " << board[2] << endl
          << "  _____" << "|" << "_____" << "|" << "_____" << endl
          << "       " << "|" << "     " << "|" << endl
          << "    " << board[3] << "  |  "<< board[4] << "  |  " << board[5] << endl
          << "  _____" << "|" << "_____" << "|" << "_____" << endl
          << "       " << "|" << "     " << "|" << endl
          << "    " << board[6] << "  |  "<< board[7] << "  |  " << board[8] << endl
          << "       " << "|" << "     " << "|" << endl << endl;
}