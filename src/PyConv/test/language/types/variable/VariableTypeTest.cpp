#include "test/catch.hpp"

#include "main/language/types/variable/VariableType.hpp"

TEST_CASE("VariableType class") {
    using pyconv::language::types::variable::VariableType;

    SECTION("Variable Type To String") {
        CHECK(VariableType::variableTypeToString(VariableType::DOUBLE) == "double");
        CHECK(VariableType::variableTypeToString(VariableType::INT) == "int");
        CHECK(VariableType::variableTypeToString(VariableType::STRING) == "string");
        CHECK(VariableType::variableTypeToString(VariableType::UNKNOWN) == "unknown");
    }

    SECTION("String To Variable Type") {
        CHECK(VariableType::stringToVariableType("double") == VariableType::DOUBLE);
        CHECK(VariableType::stringToVariableType("int") == VariableType::INT);
        CHECK(VariableType::stringToVariableType("string") == VariableType::STRING);
        CHECK(VariableType::stringToVariableType("weird") == VariableType::UNKNOWN);
    }
}
