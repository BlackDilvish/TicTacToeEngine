#include "parser.hpp"
#include <cctype>
#include <exception>

std::vector<std::pair<size_t, size_t>> Parser::getMovesFromInputString(const std::string& content, char token)
{
    std::vector<std::pair<size_t, size_t>> moves;

    for (const auto& t : split(content, token))
    {
        auto move = getMoveFromToken(t);

        moves.push_back(move);
    }

    return moves;
}

std::vector<std::string> Parser::split(const std::string& content, char token)
{
    std::vector<std::string> result;

    auto begin = content.begin();
    for (auto it = begin; it != content.end(); it++)
    {
        if (*it == token)
        {
            result.push_back(std::string(begin, it));
            begin = it+1;
        }
    }

    result.push_back(std::string(begin, content.end()));

    return result;
}

std::pair<size_t, size_t> Parser::getMoveFromToken(const std::string& token)
{
    if (isTokenParsable(token))
    {
        int row = token[0] - '0';
        int col = token[1] - '0';

        return std::make_pair(row, col);
    }
    else
    {
        throw std::runtime_error("Input token: " + token + " is invalid");
    }
}

bool Parser::isTokenParsable(const std::string& token)
{
    return token.size() == 2 && std::isdigit(token[0]) && isdigit(token[0]);
}