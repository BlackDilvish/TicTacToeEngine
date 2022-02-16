#include<iostream>
#include"board.hpp"
#include"solver.hpp"

int main()
{
    Board<char, 3> ticTacToe{
        {'x', 'o', 'x',
         '.', 'x', 'o',
         'x', 'o', 'o'},
        '.'
    };

    std::cout << ticTacToe;

    Solver<char, 3> solver(ticTacToe);

    std::cout << solver.evaluatePosition(ticTacToe, 'x', true) << "\n";
    std::cout << ticTacToe.isFull() << "\n";

    return 0;
}