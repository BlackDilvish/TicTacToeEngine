#pragma once

#include<iostream>
#include<array>

template<typename T, size_t N>
class Board
{
public:
    Board() = default;
    Board(const std::array<T, N>& position)
    : m_board(position)
    {

    }

    std::array<T, N> getPosition() const { return m_board; }

    friend std::ostream& operator<<(std::ostream& os, const Board& board)
    {
        os << "print";
        return os;
    }

private:
    std::array<T, N> m_board { T() };
};