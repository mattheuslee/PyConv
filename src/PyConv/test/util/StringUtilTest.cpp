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

    SECTION("To Lower Case") {
        CHECK(StringUtil::toLowerCase("TEST") == "test");
    }

    SECTION("To Upper Case") {
        CHECK(StringUtil::toUpperCase("test") == "TEST");
    }
}
