#include "test/catch.hpp"

#include "main/util/language/types/line/BlankLineType.hpp"

TEST_CASE("Blank Line Type class") {
    using pyconv::util::language::types::line::BlankLineType;

    BlankLineType blankLineType;

    SECTION("Line Type") {
        CHECK(blankLineType.type() == pyconv::util::language::types::line::Type::BLANK);
    }

    SECTION("To string") {
        CHECK(blankLineType.str() == "blank line");
    }

}
