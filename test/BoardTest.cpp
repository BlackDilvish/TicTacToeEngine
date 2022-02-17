#include "gtest/gtest.h"
#include "board.hpp"

TEST(BoardTest, testGetAllMoves)
{
    Board<3>::MovesVector moves{{0,0}, {1,1}};
    Board<3> board{moves};

    EXPECT_EQ(moves, board.getMoves());
}