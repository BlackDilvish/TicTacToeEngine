#include "gtest/gtest.h"
#include "board.hpp"

TEST(BoardTest, testGetAllMoves)
{
    Board::MovesVector moves{{0,0}, {1,1}};
    Board board{3, moves};

    EXPECT_EQ(moves, board.getMoves());
}