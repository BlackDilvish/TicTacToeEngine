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


private:
    void calculateNextMove()
    {
        
    }

    Board<T, N> m_board;
};