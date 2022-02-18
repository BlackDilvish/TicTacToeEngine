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

TEST(SolverTest, testBestMoveFor4x4Board)
{
    Board<4>::MovesVector moves{{0,1}, {0,3}, {1,1}, {2,0}, {2,1}, {2,2}};
    Board<4> board{moves};

    Solver<4> solver;
    auto bestMove = solver.getNextMove(board);
    const auto winningMove = std::make_pair(3, 1);

    EXPECT_EQ(winningMove.first, bestMove.first);
    EXPECT_EQ(winningMove.second, bestMove.second);
}

TEST(SolverTest, testBestMoveFor5x5Board)
{
    Board<5>::MovesVector moves{{4,4}, {0,3}, {0,0}, {2,0}, {2,2}, {2,4}, {3,3}, {0,1}};
    Board<5> board{moves};
    size_t depth = 3;

    Solver<5> solver;
    auto bestMove = solver.getNextMove(board, depth);
    const auto winningMove = std::make_pair(1, 1);

    EXPECT_EQ(winningMove.first, bestMove.first);
    EXPECT_EQ(winningMove.second, bestMove.second);
}

TEST(SolverTest, testBestMoveFor6x6Board)
{
    Board<6>::MovesVector moves{{0,5}, {0,3}, {1,4}, {2,0}, {3,2}, {2,4}, {4,1}, {0,1}, {5,0}, {1,1}};
    Board<6> board{moves};
    size_t depth = 3;

    Solver<6> solver;
    auto bestMove = solver.getNextMove(board, depth);
    const auto winningMove = std::make_pair(2, 3);

    EXPECT_EQ(winningMove.first, bestMove.first);
    EXPECT_EQ(winningMove.second, bestMove.second);
}