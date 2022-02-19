#pragma once

#include<iostream>
#include<array>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>

class Board
{
public:
    using MovesVector = std::vector<std::pair<size_t, size_t>>;
    using Move = std::pair<size_t, size_t>;

    Board(size_t size, const MovesVector& moves);
    Board(const Board& board);

    void makeMove(const Move& move) noexcept(false);
    void undoLastMove() { m_moves.pop_back(); }

    bool isFull() const { return m_moves.size() == std::pow(m_size, 2); }
    size_t size() const { return m_size; }

    MovesVector getMoves() const { return m_moves; }
    MovesVector getPossibleMoves() const;

    friend std::ostream& operator<<(std::ostream& os, const Board& board);

private:
    size_t m_size;
    std::vector<Move> m_moves;

    void print(std::ostream& os) const;
    char getSymbol(size_t index) const;
    bool isMoveValid(const Move& move) const;
};