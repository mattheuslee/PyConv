#include "test/catch.hpp"

#include "main/util/language/LanguageType.hpp"
#include "main/util/language/types/variable/PythonVariable.hpp"

TEST_CASE("PythonVariable class") {
    using pyconv::util::language::types::variable::VariableType;

    pyconv::util::language::types::variable::PythonVariable pythonVariable;

    SECTION("Name") {
        CHECK(pythonVariable.name() == "");
        pythonVariable.name("test");
        CHECK(pythonVariable.name() == "test");
    }

    SECTION("Language Type") {
        CHECK(pythonVariable.languageType() == pyconv::util::language::LanguageType::PYTHON);
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
