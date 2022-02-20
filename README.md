# TicTacToe Engine
The program for tic-tac-toe game that finds best move for every position. It uses the minimax algorithm with alpha-beta pruning to reduce the search space.

## Algorithm
A **minimax algorithm** is a recursive algorithm for choosing the next move in an n-player game, usually a two-player, back and forth game. A value is associated with each position or state of the game. This value is computed by means of a position evaluation function and it indicates how good it would be for a player to reach that position. The player then makes the move that maximizes the minimum value of the position resulting from the opponent's possible following moves. If it is A's turn to move, A gives a value to each of his legal moves.\
**Alpha–beta pruning** is a search algorithm that seeks to decrease the number of nodes that are evaluated by the minimax algorithm in its search tree. It stops evaluating a move when at least one possibility has been found that proves the move to be worse than a previously examined move. Such moves need not be evaluated further. When applied to a standard minimax tree, it returns the same move as minimax would, but prunes away branches that cannot possibly influence the final decision.\
https://en.wikipedia.org/wiki/Alpha%E2%80%93beta_pruning

## Pseudocode
~~~~
function alphabeta(node, depth, α, β, maximizingPlayer) is
    if depth = 0 or node is a terminal node then
        return the heuristic value of node
    if maximizingPlayer then
        value := −∞
        for each child of node do
            value := max(value, alphabeta(child, depth − 1, α, β, FALSE))
            if value ≥ β then
                break (* β cutoff *)
            α := max(α, value)
        return value
    else
        value := +∞
        for each child of node do
            value := min(value, alphabeta(child, depth − 1, α, β, TRUE))
            if value ≤ α then
                break (* α cutoff *)
            β := min(β, value)
        return value
~~~~

## Usage
Project requires C++17 standard and is built using a cmake:
~~~~
mkdir build
cd build
cmake ..
make
~~~~

### Finding the best move:
Requires passing two parameters to the main function. A size of the square board and a list of moves separated by commas:
~~~~
user@user:/TicTacToeEngine/build$ ./TicTacToeEngine 3 "00,01,02,22,11,21"
x o x 
  x
  o o
2 0
~~~~
### Playing a demo game
To play a tic-tac-toe game against an engine execute the following command:
~~~~
user@user:/TicTacToeEngine/build$ ./demo/TicTacToeEngine_demo
~~~~
### Tests
Basic tests were created using the GoogleTest testing framework. Tests can be executed with:
~~~~
user@user:/TicTacToeEngine/build$ make test
~~~~
