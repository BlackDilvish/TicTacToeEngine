#include "gtest/gtest.h"
#include "solver.hpp"

TEST(SolverTest, testBestMoveFor3x3BoardFirstPlayer)
{
    Board::MovesVector moves{{0,0}, {1,1}, {1,0}, {0,1}};
    Board board{3, moves};

    Solver solver;
    auto bestMove = solver.getNextMove(board);
    const auto winningMove = std::make_pair(2, 0);

    EXPECT_EQ(winningMove.first, bestMove.first);
    EXPECT_EQ(winningMove.second, bestMove.second);
}

TEST(SolverTest, testBestMoveFor3x3BoardSecondPlayer)
{
    Board::MovesVector moves{{0,0}, {1,1}, {1,0}};
    Board board{3, moves};
    const size_t depth = 5;

    Solver solver;
    auto bestMove = solver.getNextMove(board, depth, false);
    const auto winningMove = std::make_pair(2, 0);

    EXPECT_EQ(winningMove.first, bestMove.first);
    EXPECT_EQ(winningMove.second, bestMove.second);
}

TEST(SolverTest, testBestMoveFor4x4BoardFirstPlayer)
{
    Board::MovesVector moves{{0,1}, {0,3}, {1,1}, {2,0}, {2,1}, {2,2}};
    Board board{4, moves};

    Solver solver;
    auto bestMove = solver.getNextMove(board);
    const auto winningMove = std::make_pair(3, 1);

    EXPECT_EQ(winningMove.first, bestMove.first);
    EXPECT_EQ(winningMove.second, bestMove.second);
}

TEST(SolverTest, testBestMoveFor4x4BoardSecondPlayer)
{
    Board::MovesVector moves{{0,1}, {0,3}, {1,1}, {2,0}, {2,1}};
    Board board{4, moves};
    const size_t depth = 5;

    Solver solver;
    auto bestMove = solver.getNextMove(board, depth, false);
    const auto winningMove = std::make_pair(3, 1);

    EXPECT_EQ(winningMove.first, bestMove.first);
    EXPECT_EQ(winningMove.second, bestMove.second);
}

TEST(SolverTest, testBestMoveFor5x5BoardFirstPlayer)
{
    Board::MovesVector moves{{4,4}, {0,3}, {0,0}, {2,0}, {2,2}, {2,4}, {3,3}, {0,1}};
    Board board{5, moves};
    const size_t depth = 3;

    Solver solver;
    auto bestMove = solver.getNextMove(board, depth);
    const auto winningMove = std::make_pair(1, 1);

    EXPECT_EQ(winningMove.first, bestMove.first);
    EXPECT_EQ(winningMove.second, bestMove.second);
}

TEST(SolverTest, testBestMoveFor5x5BoardSecondPlayer)
{
    Board::MovesVector moves{{4,4}, {0,3}, {0,0}, {2,0}, {2,2}, {2,4}, {3,3}};
    Board board{5, moves};
    const size_t depth = 3;

    Solver solver;
    auto bestMove = solver.getNextMove(board, depth, false);
    const auto winningMove = std::make_pair(1, 1);

    EXPECT_EQ(winningMove.first, bestMove.first);
    EXPECT_EQ(winningMove.second, bestMove.second);
}

TEST(SolverTest, testBestMoveFor6x6BoardFirstPlayer)
{
    Board::MovesVector moves{{0,5}, {0,3}, {1,4}, {2,0}, {3,2}, {2,4}, {4,1}, {0,1}, {5,0}, {1,1}};
    Board board{6, moves};
    const size_t depth = 3;

    Solver solver;
    auto bestMove = solver.getNextMove(board, depth);
    const auto winningMove = std::make_pair(2, 3);

    EXPECT_EQ(winningMove.first, bestMove.first);
    EXPECT_EQ(winningMove.second, bestMove.second);
}

TEST(SolverTest, testBestMoveFor6x6BoardSecondPlayer)
{
    Board::MovesVector moves{{0,5}, {0,3}, {1,4}, {2,0}, {3,2}, {2,4}, {4,1}, {0,1}, {5,0}};
    Board board{6, moves};
    const size_t depth = 3;

    Solver solver;
    auto bestMove = solver.getNextMove(board, depth, false);
    const auto winningMove = std::make_pair(2, 3);

    EXPECT_EQ(winningMove.first, bestMove.first);
    EXPECT_EQ(winningMove.second, bestMove.second);
}