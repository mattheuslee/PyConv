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

    SECTION("Preprocess") {
        auto lines = TestUtil::getSamplePythonLineStrings();
        auto processedLines = Parser<LanguageType::PYTHON>::preprocess(lines).first;

        REQUIRE(processedLines.size() == TestUtil::SAMPLE_NUM_LINES);
        auto idx = 0;
        CHECK(processedLines[idx].line() == "i = 5");
        CHECK(processedLines[idx].languageType() == LanguageType::PYTHON);
        CHECK(processedLines[idx].lineType() == LineType::VARIABLE_DECLARATION);
        CHECK(processedLines[idx].numWhitespace() == 0);
        CHECK(processedLines[idx].indentationLevel() == 0);

        ++idx;
        CHECK(processedLines[idx].line() == "i = 10");
        CHECK(processedLines[idx].languageType() == LanguageType::PYTHON);
        CHECK(processedLines[idx].lineType() == LineType::VARIABLE_ASSIGNMENT);
        CHECK(processedLines[idx].numWhitespace() == 0);
        CHECK(processedLines[idx].indentationLevel() == 0);

        ++idx;
        CHECK(processedLines[idx].line() == "j = i");
        CHECK(processedLines[idx].languageType() == LanguageType::PYTHON);
        CHECK(processedLines[idx].lineType() == LineType::VARIABLE_DECLARATION);
        CHECK(processedLines[idx].numWhitespace() == 0);
        CHECK(processedLines[idx].indentationLevel() == 0);

        ++idx;
        CHECK(processedLines[idx].line() == "for k in {0, 10}:");
        CHECK(processedLines[idx].languageType() == LanguageType::PYTHON);
        CHECK(processedLines[idx].lineType() == LineType::FOR_LOOP);
        CHECK(processedLines[idx].numWhitespace() == 0);
        CHECK(processedLines[idx].indentationLevel() == 0);

        ++idx;
        CHECK(processedLines[idx].line() == "if k == 5:");
        CHECK(processedLines[idx].languageType() == LanguageType::PYTHON);
        CHECK(processedLines[idx].lineType() == LineType::IF_STATEMENT);
        CHECK(processedLines[idx].numWhitespace() == 4);
        CHECK(processedLines[idx].indentationLevel() == 1);

        ++idx;
        CHECK(processedLines[idx].line() == "print (\"5!\")");
        CHECK(processedLines[idx].languageType() == LanguageType::PYTHON);
        CHECK(processedLines[idx].lineType() == LineType::PRINT_STATEMENT);
        CHECK(processedLines[idx].numWhitespace() == 8);
        CHECK(processedLines[idx].indentationLevel() == 2);

        ++idx;
        CHECK(processedLines[idx].line() == "elif k == 10:");
        CHECK(processedLines[idx].languageType() == LanguageType::PYTHON);
        CHECK(processedLines[idx].lineType() == LineType::ELIF_STATEMENT);
        CHECK(processedLines[idx].numWhitespace() == 4);
        CHECK(processedLines[idx].indentationLevel() == 1);

        ++idx;
        CHECK(processedLines[idx].line() == "print (\"10!\")");
        CHECK(processedLines[idx].languageType() == LanguageType::PYTHON);
        CHECK(processedLines[idx].lineType() == LineType::PRINT_STATEMENT);
        CHECK(processedLines[idx].numWhitespace() == 8);
        CHECK(processedLines[idx].indentationLevel() == 2);

        ++idx;
        CHECK(processedLines[idx].line() == "else:");
        CHECK(processedLines[idx].languageType() == LanguageType::PYTHON);
        CHECK(processedLines[idx].lineType() == LineType::ELSE_STATEMENT);
        CHECK(processedLines[idx].numWhitespace() == 4);
        CHECK(processedLines[idx].indentationLevel() == 1);

        ++idx;
        CHECK(processedLines[idx].line() == "print (\"Not 5 or 10!\")");
        CHECK(processedLines[idx].languageType() == LanguageType::PYTHON);
        CHECK(processedLines[idx].lineType() == LineType::PRINT_STATEMENT);
        CHECK(processedLines[idx].numWhitespace() == 8);
        CHECK(processedLines[idx].indentationLevel() == 2);

        ++idx;
        CHECK(processedLines[idx].line() == "");
        CHECK(processedLines[idx].languageType() == LanguageType::PYTHON);
        CHECK(processedLines[idx].lineType() == LineType::BLANK);
        CHECK(processedLines[idx].numWhitespace() == 0);
        CHECK(processedLines[idx].indentationLevel() == 0);
    }
}
