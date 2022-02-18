#pragma once

#include<string>
#include<vector>
#include<iostream>

class Parser
{
public:
    std::vector<std::pair<size_t, size_t>> getMovesFromInputString(const std::string& content, char token);

private:
    std::vector<std::string> split(const std::string& content, char token);
    std::pair<size_t, size_t> getMoveFromToken(const std::string& token) noexcept(false);
    bool isTokenParsable(const std::string& token);
};