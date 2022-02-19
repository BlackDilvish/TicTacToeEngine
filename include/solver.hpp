#pragma once

#include<climits>
#include"board.hpp"

class Solver
{
public:
    std::pair<size_t, size_t> getNextMove(const Board& board, size_t depth = 5);
    int getGameResult(const Board& board);

private:
    int alphabeta(Board& board, size_t depth, bool isMaximizing, int alpha = INT_MIN, int beta = INT_MAX);
    int evaluatePosition(const Board& board);
};
