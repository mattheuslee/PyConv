#include "test/catch.hpp"

#include "main/util/language/types/variable/UnknownVariableType.hpp"

TEST_CASE("Unknown Variable Type class") {
    using pyconv::util::language::types::variable::UnknownVariableType;

    UnknownVariableType unknownVariableType;

    SECTION("Var Type") {
        CHECK(unknownVariableType.varType() == pyconv::util::language::types::variable::VarType::UNKNOWN);
    }

    SECTION("To string") {
        CHECK(unknownVariableType.str() == "unknown");
    }

}