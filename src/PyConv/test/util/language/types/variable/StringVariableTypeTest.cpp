#include "test/catch.hpp"

#include "main/util/language/types/variable/StringVariableType.hpp"

TEST_CASE("String Variable Type class") {
    using pyconv::util::language::types::variable::StringVariableType;

    StringVariableType stringVariableType;

    SECTION("Var Type") {
        CHECK(stringVariableType.varType() == pyconv::util::language::types::variable::VarType::STRING);
    }

    SECTION("To string") {
        CHECK(stringVariableType.str() == "string");
    }

}
