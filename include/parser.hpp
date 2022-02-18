#pragma once

#include<string>
#include<vector>
#include<array>
#include<iostream>

class Parser
{
public:
    void parse(const std::array<std::string, 2>& input);
    std::vector<std::pair<size_t, size_t>> getMoves() const;
    size_t getDimension() const;

private:
    void extractBoardDimention(const std::string& content);

    void extractMovesInput(const std::string& content, char token);
    std::vector<std::string> split(const std::string& content, char token);
    std::pair<size_t, size_t> getMoveFromToken(const std::string& token) noexcept(false);

    bool isNumber(const std::string& token);
    bool isTokenParsable(const std::string& token);

    std::vector<std::pair<size_t, size_t>> m_moves;
    size_t m_dimension;
};