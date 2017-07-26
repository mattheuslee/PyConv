#include "test/catch.hpp"

#include "main/util/language/types/variable/IntVariableType.hpp"

TEST_CASE("Int Variable Type class") {
    using pyconv::util::language::types::variable::IntVariableType;

    IntVariableType intVariableType;

    SECTION("Var Type") {
        CHECK(intVariableType.varType() == pyconv::util::language::types::variable::VarType::INT);
    }

    SECTION("To string") {
        CHECK(intVariableType.str() == "int");
    }

}