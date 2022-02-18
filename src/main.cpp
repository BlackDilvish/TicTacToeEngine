#include<iostream>
#include"board.hpp"
#include"solver.hpp"
#include"parser.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "Invalid number of parameters. Please specify an input.\n";
        return -1;
    }
    std::string input = argv[1]; //"00,01,02,22,11,21"
    Parser parser;
    auto moves = parser.getMovesFromInputString(input, ',');

    Board<3> ticTacToe (moves);

    Solver<3> solver;

    std::cout << ticTacToe;
    auto move1 = solver.getNextMove(ticTacToe);
    std::cout << move1.first << " " << move1.second << "\n";

    return 0;
}