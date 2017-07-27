#include "test/catch.hpp"

#include "main/util/language/types/variable/StringVariableType.hpp"

TEST_CASE("String Variable Type class") {
    using pyconv::util::language::types::variable::StringVariableType;

    StringVariableType stringVariableType;

    SECTION("Var Type") {
        CHECK(stringVariableType.type() == pyconv::util::language::types::variable::Type::STRING);
    }

    SECTION("To string") {
        CHECK(stringVariableType.str() == "string");
    }

}
