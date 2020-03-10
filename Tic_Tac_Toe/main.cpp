#include "GameBoard.hpp"

using namespace std;

int main (void)
{
    GameBoard* newBoard;
    char answer;

    do
    {
        newBoard = new GameBoard();
        newBoard->gamePlay();

        delete newBoard;

        system("CLS");
        cout << "Want to play again? (y to continue or n to exit)" << endl;
        cin >> answer;
        if (answer == 'y')
            continue;
        else
            break;

    } while (1);

    return 0;
}
