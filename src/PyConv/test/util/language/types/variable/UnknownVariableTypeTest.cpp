#include "test/catch.hpp"

#include "main/util/language/types/variable/UnknownVariableType.hpp"

TEST_CASE("Unknown Variable Type class") {
    using pyconv::util::language::types::variable::UnknownVariableType;

    UnknownVariableType unknownVariableType;

    SECTION("Var Type") {
        CHECK(unknownVariableType.type() == pyconv::util::language::types::variable::Type::UNKNOWN);
    }

    SECTION("To string") {
        CHECK(unknownVariableType.str() == "unknown");
    }

}
