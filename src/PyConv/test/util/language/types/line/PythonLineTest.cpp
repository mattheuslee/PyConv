#include "test/catch.hpp"

#include "main/util/language/LanguageType.hpp"
#include "main/util/language/types/line/PythonLine.hpp"

TEST_CASE("PythonLine class") {
    using pyconv::util::language::types::line::LineType;

    pyconv::util::language::types::line::PythonLine pythonLine;

    SECTION("Line") {
        CHECK(pythonLine.line() == "");
        pythonLine.line("test");
        CHECK(pythonLine.line() == "test");
    }

    SECTION("Language Type") {
        CHECK(pythonLine.languageType() == pyconv::util::language::LanguageType::PYTHON);
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
}
