#include<iostream>
#include"board.hpp"
#include"solver.hpp"

int main()
{
    Board<3> ticTacToe ({{0,0}, {0,1}, {0,2}, {2,2}, {1,1}, {2,1}});
    Board<3> ticTacToe2 ({{0,0}, {2,0}, {0,2}, {1,1}, {2,1}});

    Solver<3> solver(ticTacToe);

    std::cout << ticTacToe;
    std::cout << solver.alphabeta(ticTacToe2, 5, true) << "\n";

    std::cout << ticTacToe2;
    std::cout << solver.alphabeta(ticTacToe2, 5, false) << "\n";

    return 0;
}