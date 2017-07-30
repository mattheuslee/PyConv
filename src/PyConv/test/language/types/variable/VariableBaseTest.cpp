#include "test/catch.hpp"

#include "main/language/LanguageType.hpp"
#include "main/language/types/variable/VariableBase.hpp"
#include "main/language/types/variable/VariableType.hpp"

TEST_CASE("VariableBase class") {
    using pyconv::language::LanguageType;
    using pyconv::language::types::variable::VariableBase;
    using pyconv::language::types::variable::VariableType;

    VariableBase variableBase;

    SECTION("Name") {
        CHECK(variableBase.name() == "");
        variableBase.name("test");
        CHECK(variableBase.name() == "test");
    }

    SECTION("Language Type") {
        CHECK(variableBase.languageType() == LanguageType::UNKNOWN);
    }

    SECTION("Variable Type") {
        CHECK(variableBase.variableType() == VariableType::UNKNOWN);
        variableBase.variableType(VariableType::DOUBLE);
        CHECK(variableBase.variableType() == VariableType::DOUBLE);
    }
}
