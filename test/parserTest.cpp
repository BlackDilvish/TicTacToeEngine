#include "gtest/gtest.h"
#include "parser.hpp"

TEST(ParserTest, testGettingMovesFromInputStringValid)
{
    const std::array<std::string, 2> input = {"3", "00,01,02,22,11,21"};
    const std::vector<std::pair<size_t, size_t>> expectedMoves{{0,0}, {0,1}, {0,2}, {2,2}, {1,1}, {2,1}};

    Parser parser;
    parser.parse(input);
    auto parsedMoves = parser.getMoves();

    EXPECT_EQ(expectedMoves.size(), parsedMoves.size());

    for (size_t i=0; i<parsedMoves.size(); i++)
    {
        EXPECT_EQ(expectedMoves[i].first, parsedMoves[i].first);
        EXPECT_EQ(expectedMoves[i].second, parsedMoves[i].second);
    }
}

TEST(ParserTest, testGettingMovesFromInputStringInvalid)
{
    const std::array<std::string, 2> input = {"3", "00,01,02;22,11,21"};
    const std::string errorMessage = "Input token: 02;22 is invalid";

    Parser parser;

    try
    {
        parser.parse(input);
        FAIL() << "Expected std::runtime_error";
    }
    catch(const std::runtime_error& e)
    {
        EXPECT_EQ(e.what(), errorMessage);
    }
}

TEST(ParserTest, testGettingDimensionFromInputStringValid)
{
    const std::array<std::string, 2> input = {"3", "00,01,02,22,11,21"};
    const size_t expectedDimension{3};

    Parser parser;
    parser.parse(input);
    size_t parsedDimension = parser.getDimension();

    EXPECT_EQ(expectedDimension, parsedDimension);
}

TEST(ParserTest, testGettingDimensionFromInputStringInvalid)
{
    const std::array<std::string, 2> input = {"three", "00,01,02,22,11,21"};
    const std::string errorMessage = "Dimension parameter: three is NaN";

    Parser parser;

    try
    {
        parser.parse(input);
        FAIL() << "Expected std::runtime_error";
    }
    catch(const std::runtime_error& e)
    {
        EXPECT_EQ(e.what(), errorMessage);
    }
}