#include "test/catch.hpp"

#include <utility>

#include "main/model/VariableMap.hpp"
#include "main/language/types/variable/Variable.hpp"
#include "main/language/types/variable/VariableType.hpp"

TEST_CASE("VariableMapTest class") {
    using pyconv::model::VariableMap;
    using pyconv::language::types::variable::Variable;
    using pyconv::language::types::variable::VariableType;

    VariableMap variableMap;

    SECTION("Add") {
        Variable variable;
        variable.name("test");
        CHECK(variableMap.add(variable));
        CHECK_FALSE(variableMap.add(variable));
        variable.name("test2");
        CHECK(variableMap.add(variable));
    }

    SECTION("Find") {
        Variable variable;
        variable.name("test");
        CHECK_FALSE(variableMap.find(variable.name()).first);
        CHECK(variableMap.add(variable));
        CHECK(variableMap.find(variable.name()).first);
        CHECK(variableMap.find(variable.name()).second.name() == variable.name());
    }

    SECTION("Find Type") {
        Variable variable;
        variable.name("test");
        variable.variableType(VariableType::INT);
        CHECK(variableMap.add(variable));
        CHECK(variableMap.findType("test") == VariableType::INT);
    }
}
