#include "test/catch.hpp"

#include "main/util/language/types/variable/DoubleVariableType.hpp"

TEST_CASE("Double Variable Type class") {
    using pyconv::util::language::types::variable::DoubleVariableType;

    DoubleVariableType doubleVariableType;

    SECTION("Var Type") {
        CHECK(doubleVariableType.type() == pyconv::util::language::types::variable::Type::DOUBLE);
    }

    SECTION("To string") {
        CHECK(doubleVariableType.str() == "double");
    }

}
