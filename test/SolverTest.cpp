#include "gtest/gtest.h"
#include "solver.hpp"

TEST(SolverTest, testBestMoveFor3x3Board)
{
    Board<3>::MovesVector moves{{0,0}, {1,1}, {1,0}, {0,1}};
    Board<3> board{moves};

    Solver<3> solver;
    auto bestMove = solver.getNextMove(board);
    const auto winningMove = std::make_pair(2, 0);

    EXPECT_EQ(winningMove.first, bestMove.first);
    EXPECT_EQ(winningMove.second, bestMove.second);
}
