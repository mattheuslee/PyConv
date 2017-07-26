#include "test/catch.hpp"

#include "main/util/language/types/variable/DoubleVariableType.hpp"

TEST_CASE("Double Variable Type class") {
    using pyconv::util::language::types::variable::DoubleVariableType;

    DoubleVariableType doubleVariableType;

    SECTION("Var Type") {
        CHECK(doubleVariableType.varType() == pyconv::util::language::types::variable::VarType::DOUBLE);
    }

    SECTION("To string") {
        CHECK(doubleVariableType.str() == "double");
    }

}
