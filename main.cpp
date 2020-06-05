#include "title.h"
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    char mowement[6];
    char board[9][9] = {{'1', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                        {'2', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                        {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'7', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                        {'8', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                        {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
    drawb(board);

    while (1) {
        cout << "make a move:" << endl;
        cin >> mowement;
        cout << endl;
        move(mowement, board);
        drawb(board);
    }
    return 0;
}
