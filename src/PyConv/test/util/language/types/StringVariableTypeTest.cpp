#include "test/catch.hpp"

#include "main/util/language/types/StringVariableType.hpp"

TEST_CASE("String Variable Type class") {
    using pyconv::util::language::types::StringVariableType;

    StringVariableType stringVariableType;

    SECTION("Var Type") {
        CHECK(stringVariableType.varType() == pyconv::util::language::types::VarType::STRING);
    }

    SECTION("To string") {
        CHECK(stringVariableType.str() == "string");
    }

}