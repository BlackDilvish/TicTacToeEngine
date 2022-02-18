#include "gtest/gtest.h"
#include "parser.hpp"

TEST(ParserTest, testGettingMovesFromInputStringValid)
{
    const std::string input = "00,01,02,22,11,21";
    const std::vector<std::pair<size_t, size_t>> expectedMoves{{0,0}, {0,1}, {0,2}, {2,2}, {1,1}, {2,1}};

    Parser parser;
    auto parsedMoves = parser.getMovesFromInputString(input, ',');

    EXPECT_EQ(expectedMoves.size(), parsedMoves.size());

    for (size_t i=0; i<parsedMoves.size(); i++)
    {
        EXPECT_EQ(expectedMoves[i].first, parsedMoves[i].first);
        EXPECT_EQ(expectedMoves[i].second, parsedMoves[i].second);
    }
}

TEST(ParserTest, testGettingMovesFromInputStringInvalid)
{
    const std::string input = "00,01,02;22,11,21";
    const std::string errorMessage = "Input token: 02;22 is invalid";

    Parser parser;

    try
    {
        auto parsedMoves = parser.getMovesFromInputString(input, ',');
        FAIL() << "Expected std::runtime_error";
    }
    catch(const std::runtime_error& e)
    {
        EXPECT_EQ(e.what(), errorMessage);
    }
}