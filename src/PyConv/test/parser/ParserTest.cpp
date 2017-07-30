#include "test/catch.hpp"

#include <string>
#include <vector>

#include "main/language/LanguageType.hpp"
#include "main/language/types/line/Line.hpp"
#include "main/language/types/line/LineType.hpp"
#include "main/parser/Parser.hpp"

TEST_CASE("Parser class") {
    using std::string;
    using std::vector;
    using pyconv::language::LanguageType;
    using pyconv::language::types::line::Line;
    using pyconv::language::types::line::LineType;
    using pyconv::parser::Parser;

    SECTION("Process") {
        vector<string> lines {
            "i = 5",
            "if i == 5:",
            "    print \"5!\"",
            "else:",
            "    print \"not 5!\"",
            ""
        };
        vector<Line<LanguageType::PYTHON>> processedLines = Parser<LanguageType::PYTHON>::process(lines);
        REQUIRE(processedLines.size() == 6);
        CHECK(processedLines[0].line() == "i = 5");
        CHECK(processedLines[0].languageType() == LanguageType::PYTHON);
        CHECK(processedLines[0].lineType() == LineType::VARIABLE);
        CHECK(processedLines[0].numWhitespace() == 0);
        CHECK(processedLines[0].indentationLevel() == 0);

        CHECK(processedLines[1].line() == "if i == 5:");
        CHECK(processedLines[1].languageType() == LanguageType::PYTHON);
        CHECK(processedLines[1].lineType() == LineType::IF_STATEMENT);
        CHECK(processedLines[1].numWhitespace() == 0);
        CHECK(processedLines[1].indentationLevel() == 0);

        CHECK(processedLines[2].line() == "print \"5!\"");
        CHECK(processedLines[2].languageType() == LanguageType::PYTHON);
        CHECK(processedLines[2].lineType() == LineType::PRINT_STATEMENT);
        CHECK(processedLines[2].numWhitespace() == 4);
        CHECK(processedLines[2].indentationLevel() == 1);

        CHECK(processedLines[3].line() == "else:");
        CHECK(processedLines[3].languageType() == LanguageType::PYTHON);
        CHECK(processedLines[3].lineType() == LineType::ELSE_STATEMENT);
        CHECK(processedLines[3].numWhitespace() == 0);
        CHECK(processedLines[3].indentationLevel() == 0);

        CHECK(processedLines[4].line() == "print \"not 5!\"");
        CHECK(processedLines[4].languageType() == LanguageType::PYTHON);
        CHECK(processedLines[4].lineType() == LineType::PRINT_STATEMENT);
        CHECK(processedLines[4].numWhitespace() == 4);
        CHECK(processedLines[4].indentationLevel() == 1);

        CHECK(processedLines[5].line() == "");
        CHECK(processedLines[5].languageType() == LanguageType::PYTHON);
        CHECK(processedLines[5].lineType() == LineType::BLANK);
        CHECK(processedLines[5].numWhitespace() == 0);
        CHECK(processedLines[5].indentationLevel() == 0);
    }
}
