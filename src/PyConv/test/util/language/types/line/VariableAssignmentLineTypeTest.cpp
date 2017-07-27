#include "test/catch.hpp"

#include "main/util/language/types/line/VariableAssignmentLineType.hpp"

TEST_CASE("Variable Assignment Line Type class") {
    using pyconv::util::language::types::line::VariableAssignmentLineType;

    VariableAssignmentLineType variableAssignmentLineType;

    SECTION("Line Type") {
        CHECK(variableAssignmentLineType.type() == pyconv::util::language::types::line::Type::VARIABLE_ASSIGNMENT);
    }

    SECTION("To string") {
        CHECK(variableAssignmentLineType.str() == "variable assignment");
    }

}
