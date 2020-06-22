#include "title.h"
#include <cstring>
#include <iostream>
#include <stdlib.h>

using namespace std;

int x1 = 0, x2 = 0;
int y1 = 0, y2 = 0;
int checking;

void move(char mowement[], char board[][9])
{
    if (strlen(mowement) == 5) {
        checking = 0;
        if (editb(mowement, board, checking)) {
            movePP(board);
        }
    } else {
        checking = 1;
        if (editb(mowement, board, checking)) {
            moveP(mowement, board);
        }
    }
}

void movePP(char board[][9])
{
    if (board[y1 - 1][x1] == 'p') {
        board[y1 - 1][x1] = ' ';
        board[y2 - 1][x2] = 'p';
    } else if (board[y1 - 1][x1] == 'P') {
        board[y1 - 1][x1] = ' ';
        board[y2 - 1][x2] = 'P';
    } else {
        cout << "Incorrect input. This not a pawn" << endl << endl;
    }
}

void moveP(char mowement[], char board[][9])
{
    if (board[y1 - 1][x1] == mowement[0]) {
        board[y1 - 1][x1] = ' ';
        board[y2 - 1][x2] = mowement[0];
    }
}

bool editb(char mowement[], char board[][9], int checking)
{
    string transformIntoInt = " ";
    int outOfBoard1 = 0, outOfBoard2 = 9;
    switch (mowement[0 + checking]) {
    case 'a':
        x1 = 1;
        break;
    case 'b':
        x1 = 2;
        break;
    case 'c':
        x1 = 3;
        break;
    case 'd':
        x1 = 4;
        break;
    case 'e':
        x1 = 5;
        break;
    case 'f':
        x1 = 6;
        break;
    case 'g':
        x1 = 7;
        break;
    case 'h':
        x1 = 8;
        break;
    default: {
        cout << "Incorrect input" << endl << endl;
        return false;
    }; break;
    }

    switch (mowement[3 + checking]) {
    case 'a':
        x2 = 1;
        break;
    case 'b':
        x2 = 2;
        break;
    case 'c':
        x2 = 3;
        break;
    case 'd':
        x2 = 4;
        break;
    case 'e':
        x2 = 5;
        break;
    case 'f':
        x2 = 6;
        break;
    case 'g':
        x2 = 7;
        break;
    case 'h':
        x2 = 8;
        break;
    default: {
        cout << "Incorrect input" << endl << endl;
        return false;
    }; break;
    }
    transformIntoInt[0] = mowement[1 + checking];
    y1 = atoi(transformIntoInt.c_str());

    transformIntoInt[0] = mowement[4 + checking];
    y2 = atoi(transformIntoInt.c_str());

    if (y1 <= outOfBoard1 || y1 >= outOfBoard2 || x1 <= outOfBoard1
        || x1 >= outOfBoard2 || x2 <= outOfBoard1 || x2 >= outOfBoard2
        || y2 <= outOfBoard1 || y2 >= outOfBoard2
        || (board[y1 - 1][x1] == ' ')) {
        cout << "Incorrect input. Abroad board or empty cage" << endl;
        return false;
    }
    return true;
}
