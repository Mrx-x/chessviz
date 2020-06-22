#include "title.h"
#include <iostream>
using namespace std;

void drawb(char board[][9])
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
