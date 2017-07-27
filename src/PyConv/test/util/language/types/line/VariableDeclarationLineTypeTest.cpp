#include "test/catch.hpp"

#include "main/util/language/types/line/VariableDeclarationLineType.hpp"

TEST_CASE("Variable Declaration Line Type class") {
    using pyconv::util::language::types::line::VariableDeclarationLineType;

    VariableDeclarationLineType variableDeclarationLineType;

    SECTION("Line Type") {
        CHECK(variableDeclarationLineType.type() == pyconv::util::language::types::line::Type::VARIABLE_DECLARATION);
    }

    SECTION("To string") {
        CHECK(variableDeclarationLineType.str() == "variable declaration");
    }

}
