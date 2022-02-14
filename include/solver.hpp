#pragma once

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

    int alphabeta(const Board<T, N>& node, size_t depth, bool isMaximizing, int alpha, int beta)
    {
        return 0;
    }

    int evaluatePosition(const Board<T, N>& board, char symbol)
    {
        std::array<int, 2*N+2> scores {0};

        auto position = board.getPosition();

        for (size_t i=0; i<N; i++)
        {
            for (size_t j=0; j<N; j++)
            {
                int value;
                if (position[i*N + j] == symbol) value = 1;
                else if (position[i*N + j] == '.') value = 0;
                else value = -1;

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
