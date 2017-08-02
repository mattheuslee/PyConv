#include "test/catch.hpp"

#include "main/language/LanguageType.hpp"
#include "main/language/types/line/Line.hpp"
#include "main/language/types/line/LineType.hpp"

TEST_CASE("Line class") {
    using pyconv::language::LanguageType;
    using pyconv::language::types::line::Line;
    using pyconv::language::types::line::LineType;

    Line line;

    SECTION("Line") {
        CHECK(line.line() == "");
        line.line("test");
        CHECK(line.line() == "test");
    }

    SECTION("Language Type") {
        CHECK(line.languageType() == LanguageType::UNKNOWN);
        line.languageType(LanguageType::PYTHON);
        CHECK(line.languageType() == LanguageType::PYTHON);
    }

    SECTION("Line Type") {
        CHECK(line.lineType() == LineType::UNKNOWN);
        line.lineType(LineType::IF_STATEMENT);
        CHECK(line.lineType() == LineType::IF_STATEMENT);
    }

    SECTION("Num Whitespace") {
        CHECK(line.numWhitespace() == 0);
        line.numWhitespace(1);
        CHECK(line.numWhitespace() == 1);
    }

    SECTION("Indentation Level") {
        CHECK(line.indentationLevel() == 0);
        line.indentationLevel(1);
        CHECK(line.indentationLevel() == 1);
    }
}
