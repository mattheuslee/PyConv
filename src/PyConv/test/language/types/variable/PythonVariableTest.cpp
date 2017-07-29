#include "test/catch.hpp"

#include "main/language/LanguageType.hpp"
#include "main/language/types/variable/PythonVariable.hpp"

TEST_CASE("PythonVariable class") {
    using pyconv::language::LanguageType;
    using pyconv::language::types::variable::VariableType;
    using pyconv::language::types::variable::PythonVariable;

    PythonVariable pythonVariable;

    SECTION("Name") {
        CHECK(pythonVariable.name() == "");
        pythonVariable.name("test");
        CHECK(pythonVariable.name() == "test");
    }

    SECTION("Language Type") {
        CHECK(pythonVariable.languageType() == LanguageType::PYTHON);
    }

    SECTION("Variable Type") {
        CHECK(pythonVariable.variableType() == VariableType::UNKNOWN);
        pythonVariable.variableType(VariableType::DOUBLE);
        CHECK(pythonVariable.variableType() == VariableType::DOUBLE);
        pythonVariable.variableType(VariableType::INT);
        CHECK(pythonVariable.variableType() == VariableType::INT);
        pythonVariable.variableType(VariableType::STRING);
        CHECK(pythonVariable.variableType() == VariableType::STRING);
        pythonVariable.variableType(VariableType::UNKNOWN);
        CHECK(pythonVariable.variableType() == VariableType::UNKNOWN);
    }
}
