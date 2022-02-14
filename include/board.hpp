#pragma once

#include<iostream>
#include<array>

template<typename T, size_t N>
class Board
{
public:
    Board() = default;
    Board(const std::array<T, N*N>& position)
    : m_board(position)
    {

    }

    using PositionType = std::array<T, N*N>;

    PositionType getPosition() const { return m_board; }

    void print(std::ostream& os) const
    {
        const size_t rowSize = N;
        for (size_t i=0; i<rowSize; i++)
        {
            for (size_t j=0; j<rowSize; j++)
            {
                os << m_board[i*rowSize + j] << " ";
            }
            os << std::endl;
        }
        os << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Board& board)
    {
        board.print(os);
        return os;
    }

private:
    PositionType m_board { T() };
};