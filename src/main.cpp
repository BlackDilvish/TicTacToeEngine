#include<iostream>
#include"board.hpp"
#include"solver.hpp"

int main()
{
    Board<3> ticTacToe ({{0,0}, {0,1}, {0,2}, {2,2}, {1,1}, {2,1}});
    Board<3> ticTacToe2 ({{0,0}, {2,0}, {0,2}, {1,1}, {2,1}});

    Solver<3> solver(ticTacToe);

    std::cout << ticTacToe;
    std::cout << solver.alphabeta(ticTacToe, 5, false) << "\n";
    auto move1 = solver.getNextMove(ticTacToe);
    std::cout << move1.first << " " << move1.second << "\n";

    return 0;
}