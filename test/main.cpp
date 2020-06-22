#define CATCH_CONFIG_MAIN

#include "../src/title.h"
#include "../thirdparty/catch.hpp"
#include <string>
using namespace std;

char board[9][9] = {{'1', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                    {'2', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                    {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {'7', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                    {'8', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                    {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};

TEST_CASE("movePawn_1", "Correct pawn move")
{
    int checking = 0;
    char mowement[6] = "e2-e4";
    REQUIRE(editb(mowement, board, checking) == true);
}

TEST_CASE("movePawn_2", "Incorrect pawn move")
{
    int checking = 0;
    char mowement[6] = "c8-c9";
    REQUIRE(editb(mowement, board, checking) == false);
}

TEST_CASE("CorrectPieceMove", "Correct")
{
    int checking = 1;
    char mowement[7] = "Bc8-c6";
    REQUIRE(editb(mowement, board, checking) == true);
}

TEST_CASE("IncorrectPieceMove", "Incorrect")
{
    int checking = 1;
    char mowement[7] = "Qc8-c9";
    REQUIRE(editb(mowement, board, checking) == false);
}

TEST_CASE("PieceMove_1", "Abroad of board")
{
    int checking = 1;
    char mowement[7] = "Qd0-d3";
    REQUIRE(editb(mowement, board, checking) == false);
}

TEST_CASE("PieceMove_2", "Abroad of board")
{
    int checking = 1;
    char mowement[7] = "Bd9-d3";
    REQUIRE(editb(mowement, board, checking) == false);
}

TEST_CASE("PieceMove_3", "No pieces in this cell")
{
    int checking = 1;
    char mowement[7] = "Nd6-d4";
    REQUIRE(editb(mowement, board, checking) == false);
}

TEST_CASE("InvalidInput", "Invalid input")
{
    int checking = 1;
    char mowement[7] = "Nd6-i8";
    REQUIRE(editb(mowement, board, checking) == false);
}
