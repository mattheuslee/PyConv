#include "test/catch.hpp"

#include "main/language/LanguageType.hpp"
#include "main/language/types/line/LineBase.hpp"
#include "main/language/types/line/LineType.hpp"

TEST_CASE("LineBase class") {
    using pyconv::language::LanguageType;
    using pyconv::language::types::line::LineBase;
    using pyconv::language::types::line::LineType;

    LineBase lineBase;

    SECTION("Line") {
        CHECK(lineBase.line() == "");
        lineBase.line("test");
        CHECK(lineBase.line() == "test");
    }

    SECTION("Language Type") {
        CHECK(lineBase.languageType() == LanguageType::UNKNOWN);
    }

    SECTION("Line Type") {
        CHECK(lineBase.lineType() == LineType::UNKNOWN);
    }

    SECTION("Num Whitespace") {
        CHECK(lineBase.numWhitespace() == 0);
        lineBase.numWhitespace(1);
        CHECK(lineBase.numWhitespace() == 1);
    }

    SECTION("Indentation Level") {
        CHECK(lineBase.indentationLevel() == 0);
        lineBase.indentationLevel(1);
        CHECK(lineBase.indentationLevel() == 1);
    }
}
