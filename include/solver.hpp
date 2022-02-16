#pragma once

#include <climits>
#include"board.hpp"

template<size_t N>
class Solver
{
public:
    Solver() = default;
    Solver(const Board<N>& initialPosition)
    : m_board(initialPosition)
    {

    }

    Board<N> getNextPosition()
    {
        return Board<N>();
    }


// private:
    void calculateNextMove()
    {
        
    }

    int alphabeta(const Board<N>& board, size_t depth, bool isMaximizing, int alpha, int beta)
    {
        if (depth == 0 || board.isFull())
        {
            return evaluatePosition(board, isMaximizing);
        }
        else if (isMaximizing)
        {
            int value = INT_MIN;
            for (auto move : board.getPossibleMoves())
            {
                Board<N> newBoard = board;
                newBoard.makeMove(move);
                value = std::max(value, alphabeta(newBoard, depth-1, false, alpha, beta));
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
            for (auto move : board.getPossibleMoves())
            {
                Board<N> newBoard = board;
                newBoard.makeMove(move);
                value = std::max(value, alphabeta(newBoard, depth-1, true, alpha, beta));
                if (value <= alpha)
                {
                    break;
                }
                beta = std::min(beta, value);
            }
            return value;
        }
    }

    int evaluatePosition(const Board<N>& board, bool maximize)
    {
        std::array<int, 2*N+2> scores {0};
        auto moves = board.getMoves();
        bool firstPlayerMove = true;

        for (const auto& move : moves)
        {
            const auto [row, col] = move;
            int value = maximize ? 1 : -1;
            value = firstPlayerMove ? value : -value;

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

    Board<N> m_board;
};
