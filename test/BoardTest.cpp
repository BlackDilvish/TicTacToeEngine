#include "gtest/gtest.h"
#include "board.hpp"

TEST(BoardTest, testGetAllMoves)
{
    Board::MovesVector moves{{0,0}, {1,1}};
    Board board{3, moves};

    EXPECT_EQ(moves, board.getMoves());
}

TEST(BoardTest, testMakeMoveValid)
{
    Board::MovesVector moves{{0,0}, {1,1}};
    Board board{3, moves};

    const auto newMove = std::make_pair(2, 2);
    board.makeMove(newMove);

    moves = board.getMoves();

    EXPECT_EQ(moves.back().first, newMove.first);
    EXPECT_EQ(moves.back().second, newMove.second);
}

TEST(BoardTest, testMakeMoveInvalid)
{
    Board::MovesVector moves{{0,0}, {1,1}};
    Board board{3, moves};

    const auto newMove = std::make_pair(1, 1);

    ASSERT_THROW(board.makeMove(newMove), std::runtime_error);
}

TEST(BoardTest, testUndoLastMove)
{
    Board::MovesVector moves{{0,0}, {1,1}};
    Board board{3, moves};

    board.undoLastMove();

    Board::MovesVector currentMoves = board.getMoves();

    EXPECT_EQ(currentMoves.size(), moves.size()-1);
}

TEST(BoardTest, testIsFullBoardFull)
{
    Board::MovesVector moves{{0,0}, {1,1}, {0,1}, {1,0}};
    Board board{2, moves};

    ASSERT_TRUE(board.isFull());
}

TEST(BoardTest, testIsFullBoardNotFull)
{
    Board::MovesVector moves{{0,0}, {1,1}, {0,1}};
    Board board{2, moves};

    ASSERT_FALSE(board.isFull());
}

TEST(BoardTest, testGetPossibleMoves)
{
    Board::MovesVector moves{{0,0}, {1,1}, {0,1}};
    Board board{2, moves};
    const auto onlyValidMove = std::make_pair(1, 0);

    auto possibleMoves = board.getPossibleMoves();
    auto possibleMove = possibleMoves.front();

    EXPECT_EQ(possibleMove.first, onlyValidMove.first);
    EXPECT_EQ(possibleMove.second, onlyValidMove.second);
}