#include "test/catch.hpp"

#include "main/util/StringUtil.hpp"

TEST_CASE("StringUtil class") {
    using pyconv::util::StringUtil;

    SECTION("Trim") {
        CHECK(StringUtil::trim("  test  ") == "test");
    }

    SECTION("Trim Leading") {
        CHECK(StringUtil::trimLeading("  test  ") == "test  ");
    }

    SECTION("Trim Trailing") {
        CHECK(StringUtil::trimTrailing("  test  ") == "  test");
    }

    SECTION("Trim Trailing Char") {
        CHECK(StringUtil::trimTrailingChar("test", ':') == "test");
        CHECK(StringUtil::trimTrailingChar("test:", ':') == "test");
        CHECK(StringUtil::trimTrailingChar("test:", ';') == "test:");
    }

    SECTION("To Lower Case") {
        CHECK(StringUtil::toLowerCase("TEST") == "test");
    }

    SECTION("To Upper Case") {
        CHECK(StringUtil::toUpperCase("test") == "TEST");
    }

    SECTION("Num Leading Whitespace") {
        CHECK(StringUtil::numLeadingWhitespace("test") == 0);
        CHECK(StringUtil::numLeadingWhitespace("  test") == 2);
        CHECK(StringUtil::numLeadingWhitespace("    test") == 4);
    }

    SECTION("Add Leading Whitespace") {
        CHECK(StringUtil::addLeadingWhitespace("test", 0) == "test");
        CHECK(StringUtil::addLeadingWhitespace("test", 4) == "    test");
        CHECK(StringUtil::addLeadingWhitespace("test", 8) == "        test");
    }

    SECTION("Extract First Word") {
        CHECK(StringUtil::extractFirstWord("") == "");
        CHECK(StringUtil::extractFirstWord("test") == "test");
        CHECK(StringUtil::extractFirstWord("test 2") == "test");
    }

    SECTION("Is All Digit") {
        CHECK(StringUtil::isAllDigit("123"));
        CHECK_FALSE(StringUtil::isAllDigit("123a"));
        CHECK_FALSE(StringUtil::isAllDigit("123!"));
    }
}
