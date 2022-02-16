#include<iostream>
#include"board.hpp"
#include"solver.hpp"

int main()
{
    Board<3> ticTacToe ({{0,0}, {0,1}, {0,2}, {2,2}, {1,1}, {2,1}, {2,0}});

    std::cout << ticTacToe;

    Solver<3> solver(ticTacToe);

    std::cout << solver.evaluatePosition(ticTacToe, true) << "\n";
    std::cout << ticTacToe.isFull() << "\n";

    return 0;
}