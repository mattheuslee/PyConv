#include "test/catch.hpp"

#include "main/language/LanguageType.hpp"
#include "main/language/types/variable/Variable.hpp"

TEST_CASE("Variable class") {
    using pyconv::language::LanguageType;
    using pyconv::language::types::variable::Variable;

    SECTION("Python Variable") {
        Variable<LanguageType::PYTHON> pythonVariable;
        CHECK(pythonVariable.languageType() == LanguageType::PYTHON);
    }

    SECTION("Cpp Variable") {
        Variable<LanguageType::CPP> cppVariable;
        CHECK(cppVariable.languageType() == LanguageType::CPP);
    }
}
