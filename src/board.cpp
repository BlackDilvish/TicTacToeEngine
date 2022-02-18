#include"board.hpp"

Board::Board(size_t size, const MovesVector& moves)
: m_size(size), m_moves(moves)
{

}

Board::Board(const Board& board)
: m_size(board.m_size), m_moves(board.m_moves)
{

}

Board::MovesVector Board::getPossibleMoves() const
{
    std::vector<bool> board(std::pow(m_size, 2));
    MovesVector possibleMoves;

    for (const auto& move : m_moves)
    {
        const auto [row, col] = move;
        board[row*m_size + col] = true;
    }
    for (size_t i=0; i<board.size(); i++)
    {
        if (board[i] == false)
        {
            possibleMoves.push_back(std::make_pair(i/m_size, i%m_size));
        }
    }

    return possibleMoves;
}

void Board::print(std::ostream& os) const
{
    std::vector<size_t> board(m_size*m_size);
    std::fill(board.begin(), board.end(), 0);
    bool firstPlayerMove = true;
    for (const auto& move : m_moves)
    {
        const auto [row, col] = move;
        board[row*m_size + col] = firstPlayerMove ? 1 : 2;
        firstPlayerMove = !firstPlayerMove;
    }

    for (size_t i=0; i<board.size(); i++)
    {
        char symbol = getSymbol(board[i]);
        os << symbol << " ";
        if ((i+1) % m_size == 0)
            os << std::endl;
    }
}

char Board::getSymbol(size_t index) const
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

std::ostream& operator<<(std::ostream& os, const Board& board)
{
    board.print(os);
    return os;
}
