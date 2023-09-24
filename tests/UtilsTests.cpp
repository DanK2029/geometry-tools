#include <gtest/gtest.h>
#include "Utils/StringUtils.h"

TEST(UtilsTests, TokenizeStringBasic)
{
	std::vector<std::string> tokenizedString = utils::tokenizeString("a,b,c,d", ',');
	std::vector<std::string> actualTokenizedString = {"a", "b", "c", "d"};
	ASSERT_EQ(actualTokenizedString.size(), tokenizedString.size());

	for (int i = 0; i < actualTokenizedString.size(); i++)
	{
		EXPECT_EQ(actualTokenizedString[i], tokenizedString[i]);
	}
}

TEST(UtilsTests, TokenizeStringEmpty)
{
	std::vector<std::string> tokenizedString = utils::tokenizeString("", ',');
	ASSERT_TRUE(tokenizedString.empty());
}

TEST(UtilsTests, TokenizeStringNoSplit)
{
	std::vector<std::string> tokenizedString = utils::tokenizeString("a,b,c,d", 'e');
	std::vector<std::string> actualTokenizedString = {"a,b,c,d"};
	ASSERT_EQ(actualTokenizedString.size(), tokenizedString.size());

	for (int i = 0; i < actualTokenizedString.size(); i++)
	{
		EXPECT_EQ(actualTokenizedString[i], tokenizedString[i]);
	}
}