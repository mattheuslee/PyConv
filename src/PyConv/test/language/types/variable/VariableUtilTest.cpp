#include "test/catch.hpp"

#include "main/language/LanguageType.hpp"
#include "main/language/types/variable/VariableType.hpp"
#include "main/language/types/variable/VariableUtil.hpp"

TEST_CASE("VariableUtil class") {
    using pyconv::language::LanguageType;
    using pyconv::language::types::variable::VariableType;
    using pyconv::language::types::variable::VariableUtil;

    SECTION("Extract Variable Name") {
        CHECK(VariableUtil<LanguageType::PYTHON>::extractVariableName("i = 5") == "i");
    }

    SECTION("Extract Variable Assignment") {
        CHECK(VariableUtil<LanguageType::PYTHON>::extractVariableAssignment("i = 3.14") == "3.14");
        CHECK(VariableUtil<LanguageType::PYTHON>::extractVariableAssignment("i = 42") == "42");
        CHECK(VariableUtil<LanguageType::PYTHON>::extractVariableAssignment("i = \"hello\"") == "\"hello\"");
        CHECK(VariableUtil<LanguageType::PYTHON>::extractVariableAssignment("i") == "");
    }

    SECTION("Get Variable Type") {
        CHECK(VariableUtil<LanguageType::PYTHON>::getVariableType("3.14") == VariableType::DOUBLE);
        CHECK(VariableUtil<LanguageType::PYTHON>::getVariableType("42") == VariableType::INT);
        CHECK(VariableUtil<LanguageType::PYTHON>::getVariableType("\"hello\"") == VariableType::STRING);
        CHECK(VariableUtil<LanguageType::PYTHON>::getVariableType("blah") == VariableType::UNKNOWN);
    }
}
