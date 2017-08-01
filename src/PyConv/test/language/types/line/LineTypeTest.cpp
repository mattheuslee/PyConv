#include "test/catch.hpp"

#include "main/language/types/line/LineType.hpp"

TEST_CASE("LineType class") {
    using pyconv::language::types::line::LineType;

    SECTION("Line Type To String") {
        CHECK(LineType::lineTypeToString(LineType::BLANK) == "blank");
        CHECK(LineType::lineTypeToString(LineType::CLOSE_BRACE) == "}");
        CHECK(LineType::lineTypeToString(LineType::ELIF_STATEMENT) == "elif");
        CHECK(LineType::lineTypeToString(LineType::ELSE_STATEMENT) == "else");
        CHECK(LineType::lineTypeToString(LineType::ELSE_IF_STATEMENT) == "else if");
        CHECK(LineType::lineTypeToString(LineType::FOR_LOOP) == "for");
        CHECK(LineType::lineTypeToString(LineType::IF_STATEMENT) == "if");
        CHECK(LineType::lineTypeToString(LineType::PRINT_STATEMENT) == "print");
        CHECK(LineType::lineTypeToString(LineType::VARIABLE) == "variable");
        CHECK(LineType::lineTypeToString(LineType::VARIABLE_ASSIGNMENT) == "variable assignment");
        CHECK(LineType::lineTypeToString(LineType::VARIABLE_DECLARATION) == "variable declaration");
        CHECK(LineType::lineTypeToString(LineType::UNKNOWN) == "unknown");
    }

    SECTION("First Word To Line Type") {
        CHECK(LineType::firstWordToLineType("") == LineType::BLANK);
        CHECK(LineType::firstWordToLineType("}") == LineType::CLOSE_BRACE);
        CHECK(LineType::firstWordToLineType("elif") == LineType::ELIF_STATEMENT);
        CHECK(LineType::firstWordToLineType("else") == LineType::ELSE_STATEMENT);
        CHECK(LineType::firstWordToLineType("for") == LineType::FOR_LOOP);
        CHECK(LineType::firstWordToLineType("if") == LineType::IF_STATEMENT);
        CHECK(LineType::firstWordToLineType("print") == LineType::PRINT_STATEMENT);
        CHECK(LineType::firstWordToLineType("i") == LineType::VARIABLE);
    }

}
