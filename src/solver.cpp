#include "solver.hpp"

std::pair<size_t, size_t> Solver::getNextMove(const Board& board, size_t depth, bool firstPlayer)
{
    Board testBoard = board;
    std::pair<size_t, size_t> bestMove;
    int bestMoveValue = firstPlayer ? INT_MIN : INT_MAX;

    for (const auto& move : testBoard.getPossibleMoves())
    {
        testBoard.makeMove(move);

        int currMoveValue = alphabeta(testBoard, depth, !firstPlayer);

        testBoard.undoLastMove();
        if ((firstPlayer && currMoveValue > bestMoveValue) || (!firstPlayer && currMoveValue < bestMoveValue))
        {
            bestMoveValue = currMoveValue;
            bestMove = move;
        }
    }

    return bestMove;
}

int Solver::alphabeta(Board& board, size_t depth, bool isMaximizing, int alpha, int beta)
{
    int heuristicValue = evaluatePosition(board);
    if (depth == 0 || board.isFull() || heuristicValue != 0)
    {
        return heuristicValue;
    }
    else if (isMaximizing)
    {
        int value = INT_MIN;
        for (const auto& move : board.getPossibleMoves())
        {
            board.makeMove(move);
            value = std::max(value, alphabeta(board, depth-1, false, alpha, beta));
            board.undoLastMove();
            if (value >= beta)
            {
                break;
            }
            alpha = std::max(alpha, value);
        }
        return value;
    }
    else
    {
        int value = INT_MAX;
        for (const auto& move : board.getPossibleMoves())
        {
            board.makeMove(move);
            value = std::min(value, alphabeta(board, depth-1, true, alpha, beta));
            board.undoLastMove();
            if (value <= alpha)
            {
                break;
            }
            beta = std::min(beta, value);
        }
        return value;
    }
}

int Solver::evaluatePosition(const Board& board)
{
    std::vector<int> scores(2*board.size()+2);
    std::fill(scores.begin(), scores.end(), 0);
    auto moves = board.getMoves();
    bool firstPlayerMove = true;

    for (const auto& move : moves)
    {
        const auto [row, col] = move;
        int value = firstPlayerMove ? 1 : -1;

        scores[row] += value;
        scores[col + board.size()] += value;

        if (row == col)
        {
            scores[scores.size()-2] += value;
        }
        if (board.size()-1-row == col)
        {
            scores[scores.size()-1] += value;
        }

        firstPlayerMove = !firstPlayerMove;
    }

    for (int result : scores)
    {
        if (result == static_cast<int>(board.size())) return 1;
        else if (result == static_cast<int>(-board.size())) return -1;
    }
    return 0;
}
