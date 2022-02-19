#include<iostream>
#include"solver.hpp"

bool gameFinished(const Board& board)
{
    Solver solver;
    int result = solver.getGameResult(board);

    if (result == 1)
    {
        std::cout << "First player won\n";
        return true;
    }
    else if (result == -1)
    {
        std::cout << "Second player won\n";
        return true;
    }
    else if (board.isFull())
    {
        std::cout << "Draw\n";
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    size_t size;
    std::cout << "Specify a board size: ";
    std::cin >> size;

    Board board(size, {});
    Solver solver;

    bool playFirst = false;
    std::cout << "Play first move? [0/1]: ";
    std::cin >> playFirst;

    if (!playFirst)
    {
        std::cout << "Bot turn...\n";
        auto botMove = solver.getNextMove(board, 15);
        board.makeMove(botMove);
        std::cout << board;
    }

    while (true)
    {
        std::cout << "Provide your move (row collumn): ";
        size_t row, col;
        std::cin >> row >> col;

        board.makeMove(std::make_pair(row, col));
        std::cout << board;

        if (gameFinished(board)) break;

        std::cout << "Bot turn...\n";
        auto botMove = solver.getNextMove(board, 15);
        board.makeMove(botMove);
        std::cout << board;

        if (gameFinished(board)) break;
    }

    return 0;
}