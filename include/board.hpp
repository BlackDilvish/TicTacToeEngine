#pragma once

#include<iostream>
#include<array>
#include<cmath>
#include<vector>
#include<algorithm>

template<size_t N>
class Board
{
public:
    using MovesVector = std::vector<std::pair<size_t, size_t>>;

    Board(const MovesVector& moves)
    : m_moves(moves)
    {

    }

    Board(const Board& board)
    : m_moves(board.m_moves)
    {

    }

    void makeMove(const std::pair<size_t, size_t>& move)
    {
        m_moves.push_back(move);
    }

    bool isFull() const
    {
        return m_moves.size() == std::pow(N, 2);
    }

    MovesVector getMoves() const
    {
        return m_moves;
    }

    MovesVector getPossibleMoves() const
    {
        std::array<bool, N*N> board { false };
        MovesVector possibleMoves;

        for (const auto& move : m_moves)
        {
            const auto [row, col] = move;
            board[row*N + col] = true;
        }
        for (int i=0; i<board.size(); i++)
        {
            if (board[i] == false)
            {
                possibleMoves.push_back(std::make_pair(i/N, i%N));
            }
        }

        return possibleMoves;
    }

    void print(std::ostream& os) const
    {
        std::array<size_t, N*N> board { 0 };
        bool firstPlayerMove = true;
        for (const auto& move : m_moves)
        {
            const auto [row, col] = move;
            board[row*N + col] = firstPlayerMove ? 1 : 2;
            firstPlayerMove = !firstPlayerMove;
        }

        for (size_t i=0; i<board.size(); i++)
        {
            char symbol = getSymbol(board[i]);
            os << symbol << " ";
            if ((i+1) % N == 0)
                os << std::endl;
        }
    }

    char getSymbol(size_t index) const
    {
        switch (index)
        {
        case 0:
            return ' ';
        case 1:
            return 'x';
        case 2:
            return 'o';        
        default:
            return '\0';
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Board& board)
    {
        board.print(os);
        return os;
    }

private:
    std::vector<std::pair<size_t, size_t>> m_moves;
};