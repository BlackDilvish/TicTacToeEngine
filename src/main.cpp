#include<iostream>
#include"board.hpp"
#include"solver.hpp"
#include"parser.hpp"

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        std::cout << "Invalid number of parameters. Please specify an input.\n";
        return -1;
    }
    Parser parser;
    parser.parse({argv[1], argv[2]}); // 3 "00,01,02,22,11,21"
    const auto moves = parser.getMoves();
    const size_t dimension = parser.getDimension();
    Board ticTacToe(dimension, moves);

    Solver solver;
    std::cout << ticTacToe;
    auto move1 = solver.getNextMove(ticTacToe);
    std::cout << move1.first << " " << move1.second << "\n";

    return 0;
}