#pragma once

#include<iostream>
#include<array>
#include<vector>
#include<algorithm>

template<typename T, size_t N>
class Board
{
public:
    Board(T defaultSymbol)
    : m_defaultSymbol(defaultSymbol)
    {
        m_board.fill(defaultSymbol);
    }

    Board(const Board& board)
    : m_board(board.m_board), m_defaultSymbol(board.m_defaultSymbol)
    {

    }

    Board(const std::array<T, N*N>& position, T defaultSymbol = T())
    : m_defaultSymbol(defaultSymbol), m_board(position)
    {

    }

    using PositionType = std::array<T, N*N>;

    PositionType getPosition() const { return m_board; }

    void makeMove(size_t pos, T symbol)
    {
        m_board[pos] = symbol;
    }

    bool isFull() const
    {
        return !std::any_of(m_board.begin(), m_board.end(), [this](T sym){ return sym == m_defaultSymbol; });
    }

    std::vector<int> getPossibleMoves() const
    {
        std::vector<int> possibleMoves;

        for (int i=0; i<N*N; i++)
        {
            if (m_board[i] == m_defaultSymbol)
            {
                possibleMoves.push_back(i);
            }
        }

        return possibleMoves;
    }

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
    const T m_defaultSymbol = T();
    PositionType m_board { T() };
};