#include<iostream>
#include"solver.hpp"

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

        std::cout << "Bot turn...\n";
        auto botMove = solver.getNextMove(board, 15, !playFirst);
        board.makeMove(botMove);
        std::cout << board;
    }

    return 0;
}