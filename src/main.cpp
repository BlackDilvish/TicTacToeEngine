#include<iostream>
#include"board.hpp"
#include"solver.hpp"

int main()
{
    Board<char, 9> ticTacToe{
        {'x', 'o', 'x',
         '.', 'x', 'o',
         'x', 'o', 'o'}
    };

    std::cout << ticTacToe;

    return 0;
}