#pragma once

#include <climits>
#include"board.hpp"

template<typename T, size_t N>
class Solver
{
public:
    Solver() = delete;
    Solver(const Board<T, N>& initialPosition)
    : m_board(initialPosition)
    {

    }

    Board<T, N> getNextPosition()
    {
        return Board<T, N>();
    }


// private:
    void calculateNextMove()
    {
        
    }

    int alphabeta(const Board<T, N>& board, size_t depth, T symbol, bool isMaximizing, int alpha, int beta)
    {
        if (depth == 0 || board.isFull())
        {
            return evaluatePosition(board, symbol);
        }
        else if (isMaximizing)
        {
            int value = INT_MIN;
            for (auto move : board.getPossibleMoves())
            {
                Board<T, N> newBoard = board;
                newBoard.makeMove(move, symbol);
                value = std::max(value, alphabeta(newBoard, depth-1, symbol, false, alpha, beta));
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
                Board<T, N> newBoard = board;
                newBoard.makeMove(move, symbol+1);
                value = std::max(value, alphabeta(newBoard, depth-1, symbol, true, alpha, beta));
                if (value <= alpha)
                {
                    break;
                }
                beta = std::min(beta, value);
            }
            return value;
        }
    }

    int evaluatePosition(const Board<T, N>& board, T symbol, bool maximize)
    {
        std::array<int, 2*N+2> scores {0};

        auto position = board.getPosition();

        for (size_t i=0; i<N; i++)
        {
            for (size_t j=0; j<N; j++)
            {
                int value = maximize ? 1 : -1;
                // if (position[i*N + j] == symbol) value;
                if (position[i*N + j] == '.') value = 0;
                else if (position[i*N + j] != symbol) value = -value;

                scores[i] += value;
                scores[N + j] += value;

                if (i == j)
                {
                    scores[scores.size()-2] += value;
                }
                if (N-1-i == j)
                {
                    scores[scores.size()-1] += value;
                }
            }
        }

        for (int result : scores)
        {
            if (result == N) return 1;
            else if (result == static_cast<int>(-N)) return -1;
        }
        return 0;
    }

    Board<T, N> m_board;
};
