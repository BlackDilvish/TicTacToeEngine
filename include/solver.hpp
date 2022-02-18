#pragma once

#include <climits>
#include"board.hpp"

template<size_t N>
class Solver
{
public:
    std::pair<size_t, size_t> getNextMove(const Board<N>& board, size_t depth = 5)
    {
        Board<N> testBoard = board;
        std::pair<size_t, size_t> bestMove;
        int bestMoveValue = INT_MIN;

        for (const auto& move : testBoard.getPossibleMoves())
        {
            testBoard.makeMove(move);

            int currMoveValue = alphabeta(testBoard, depth, false);

            testBoard.undoLastMove();

            if (currMoveValue > bestMoveValue)
            {
                bestMoveValue = currMoveValue;
                bestMove = move;
            }
        }

        return bestMove;
    }


private:
    int alphabeta(Board<N>& board, size_t depth, bool isMaximizing, int alpha = INT_MIN, int beta = INT_MAX)
    {
        int heuristicValue = evaluatePosition(board);
        if (depth == 0 || board.isFull() || heuristicValue != 0)
        {
            return heuristicValue;
        }
        else if (isMaximizing)
        {
            int value = INT_MIN;
            for (const auto& move : board.getPossibleMoves())
            {
                board.makeMove(move);
                value = std::max(value, alphabeta(board, depth-1, false, alpha, beta));
                board.undoLastMove();
                if (value >= beta)
                {
                    break;
                }
                alpha = std::max(alpha, value);
            }
            return value;
        }
        else
        {
            int value = INT_MAX;
            for (const auto& move : board.getPossibleMoves())
            {
                board.makeMove(move);
                value = std::min(value, alphabeta(board, depth-1, true, alpha, beta));
                board.undoLastMove();
                if (value <= alpha)
                {
                    break;
                }
                beta = std::min(beta, value);
            }
            return value;
        }
    }

    int evaluatePosition(const Board<N>& board)
    {
        std::array<int, 2*N+2> scores {0};
        auto moves = board.getMoves();
        bool firstPlayerMove = true;

        for (const auto& move : moves)
        {
            const auto [row, col] = move;
            int value = firstPlayerMove ? 1 : -1;

            scores[row] += value;
            scores[col + N] += value;

            if (row == col)
            {
                scores[scores.size()-2] += value;
            }
            if (N-1-row == col)
            {
                scores[scores.size()-1] += value;
            }

            firstPlayerMove = !firstPlayerMove;
        }

        for (int result : scores)
        {
            if (result == N) return 1;
            else if (result == static_cast<int>(-N)) return -1;
        }
        return 0;
    }
};
