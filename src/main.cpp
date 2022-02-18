#include<iostream>
#include"board.hpp"
#include"solver.hpp"
#include"parser.hpp"

int main()
{
    std::string input = "00,01,02,22,11,21";
    Parser parser;
    auto moves = parser.getMovesFromInputString(input, ',');

    Board<3> ticTacToe (moves);

    Solver<3> solver;

    std::cout << ticTacToe;
    // std::cout << solver.alphabeta(ticTacToe, 5, false) << "\n";
    auto move1 = solver.getNextMove(ticTacToe);
    std::cout << move1.first << " " << move1.second << "\n";

    return 0;
}