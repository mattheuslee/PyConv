#include "test/catch.hpp"

#include "main/language/LanguageType.hpp"
#include "main/language/types/line/Line.hpp"
#include "main/language/types/line/LineType.hpp"
#include "main/language/types/line/PythonLine.hpp"

TEST_CASE("PythonLine class") {
    using pyconv::language::LanguageType;
    using pyconv::language::types::line::LineType;
    using pyconv::language::types::line::PythonLine;

    PythonLine pythonLine;

    SECTION("Line") {
        CHECK(pythonLine.line() == "");
        pythonLine.line("test");
        CHECK(pythonLine.line() == "test");
    }

    SECTION("Language Type") {
        CHECK(pythonLine.languageType() == LanguageType::PYTHON);
    }

    SECTION("Line Type") {
        CHECK(pythonLine.lineType() == LineType::UNKNOWN);
        pythonLine.lineType(LineType::BLANK);
        CHECK(pythonLine.lineType() == LineType::BLANK);
        pythonLine.lineType(LineType::ELIF_STATEMENT);
        CHECK(pythonLine.lineType() == LineType::ELIF_STATEMENT);
        pythonLine.lineType(LineType::ELSE_IF_STATEMENT);
        CHECK(pythonLine.lineType() == LineType::ELSE_IF_STATEMENT);
        pythonLine.lineType(LineType::ELSE_STATEMENT);
        CHECK(pythonLine.lineType() == LineType::ELSE_STATEMENT);
        pythonLine.lineType(LineType::FOR_LOOP);
        CHECK(pythonLine.lineType() == LineType::FOR_LOOP);
        pythonLine.lineType(LineType::IF_STATEMENT);
        CHECK(pythonLine.lineType() == LineType::IF_STATEMENT);
        pythonLine.lineType(LineType::PRINT_STATEMENT);
        CHECK(pythonLine.lineType() == LineType::PRINT_STATEMENT);
        pythonLine.lineType(LineType::UNKNOWN);
        CHECK(pythonLine.lineType() == LineType::UNKNOWN);
        pythonLine.lineType(LineType::VARIABLE_ASSIGNMENT);
        CHECK(pythonLine.lineType() == LineType::VARIABLE_ASSIGNMENT);
        pythonLine.lineType(LineType::VARIABLE_DECLARATION);
        CHECK(pythonLine.lineType() == LineType::VARIABLE_DECLARATION);
    }

    SECTION("Num Whitespace") {
        CHECK(pythonLine.numWhitespace() == 0);
        pythonLine.numWhitespace(1);
        CHECK(pythonLine.numWhitespace() == 1);
        pythonLine.numWhitespace(2);
        CHECK(pythonLine.numWhitespace() == 2);
    }

    SECTION("Indentation Level") {
        CHECK(pythonLine.indentationLevel() == 0);
        pythonLine.indentationLevel(1);
        CHECK(pythonLine.indentationLevel() == 1);
        pythonLine.indentationLevel(2);
        CHECK(pythonLine.indentationLevel() == 2);
    }

}
