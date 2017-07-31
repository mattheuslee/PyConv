#include "test/catch.hpp"

#include <string>
#include <vector>

#include "main/language/LanguageType.hpp"
#include "main/language/types/line/Line.hpp"
#include "main/language/types/line/LineType.hpp"
#include "main/parser/Parser.hpp"
#include "test/TestUtil.hpp"

TEST_CASE("Parser class") {
    using std::string;
    using std::vector;
    using pyconv::language::LanguageType;
    using pyconv::language::types::line::Line;
    using pyconv::language::types::line::LineType;
    using pyconv::parser::Parser;
    using pyconv::TestUtil;

    SECTION("Process") {
        vector<string> lines = TestUtil::getSamplePythonLineStrings();

        vector<Line<LanguageType::PYTHON>> processedLines = Parser<LanguageType::PYTHON>::preProcess(lines);
        REQUIRE(processedLines.size() == 7);
        CHECK(processedLines[0].line() == "i = 5");
        CHECK(processedLines[0].languageType() == LanguageType::PYTHON);
        CHECK(processedLines[0].lineType() == LineType::VARIABLE_DECLARATION);
        CHECK(processedLines[0].numWhitespace() == 0);
        CHECK(processedLines[0].indentationLevel() == 0);

        CHECK(processedLines[1].line() == "i = 10");
        CHECK(processedLines[1].languageType() == LanguageType::PYTHON);
        CHECK(processedLines[1].lineType() == LineType::VARIABLE_ASSIGNMENT);
        CHECK(processedLines[1].numWhitespace() == 0);
        CHECK(processedLines[1].indentationLevel() == 0);

        CHECK(processedLines[2].line() == "if i == 5:");
        CHECK(processedLines[2].languageType() == LanguageType::PYTHON);
        CHECK(processedLines[2].lineType() == LineType::IF_STATEMENT);
        CHECK(processedLines[2].numWhitespace() == 0);
        CHECK(processedLines[2].indentationLevel() == 0);

        CHECK(processedLines[3].line() == "print \"5!\"");
        CHECK(processedLines[3].languageType() == LanguageType::PYTHON);
        CHECK(processedLines[3].lineType() == LineType::PRINT_STATEMENT);
        CHECK(processedLines[3].numWhitespace() == 4);
        CHECK(processedLines[3].indentationLevel() == 1);

        CHECK(processedLines[4].line() == "else:");
        CHECK(processedLines[4].languageType() == LanguageType::PYTHON);
        CHECK(processedLines[4].lineType() == LineType::ELSE_STATEMENT);
        CHECK(processedLines[4].numWhitespace() == 0);
        CHECK(processedLines[4].indentationLevel() == 0);

        CHECK(processedLines[5].line() == "print \"not 5!\"");
        CHECK(processedLines[5].languageType() == LanguageType::PYTHON);
        CHECK(processedLines[5].lineType() == LineType::PRINT_STATEMENT);
        CHECK(processedLines[5].numWhitespace() == 4);
        CHECK(processedLines[5].indentationLevel() == 1);

        CHECK(processedLines[6].line() == "");
        CHECK(processedLines[6].languageType() == LanguageType::PYTHON);
        CHECK(processedLines[6].lineType() == LineType::BLANK);
        CHECK(processedLines[6].numWhitespace() == 0);
        CHECK(processedLines[6].indentationLevel() == 0);
    }
}
