#include "test/catch.hpp"

#include "main/language/types/variable/VariableBase.hpp"
#include "main/language/types/variable/VariableMap.hpp"
#include "main/language/types/variable/VariableType.hpp"

TEST_CASE("VariableMapTest class") {
    using pyconv::language::types::variable::VariableBase;
    using pyconv::language::types::variable::VariableMap;
    using pyconv::language::types::variable::VariableType;

    VariableMap variableMap;

    SECTION("Add") {
        VariableBase variable;
        variable.name("test");
        CHECK(variableMap.add(variable));
        CHECK_FALSE(variableMap.add(variable));
        variable.name("test2");
        CHECK(variableMap.add(variable));
    }

    SECTION("Find") {
        VariableBase variable;
        variable.name("test");
        CHECK_FALSE(variableMap.find(variable.name()).first);
        CHECK(variableMap.add(variable));
        CHECK(variableMap.find(variable.name()).first);
        CHECK(variableMap.find(variable.name()).second.name() == variable.name());
    }

    SECTION("Find Type") {
        VariableBase variable;
        variable.name("test");
        variable.variableType(VariableType::INT);
        CHECK(variableMap.add(variable));
        CHECK(variableMap.findType("test") == VariableType::INT);
    }
}
