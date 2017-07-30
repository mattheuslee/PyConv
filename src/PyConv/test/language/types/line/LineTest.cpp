#include "test/catch.hpp"

#include "main/language/LanguageType.hpp"
#include "main/language/types/line/Line.hpp"

TEST_CASE("Line class") {
    using pyconv::language::LanguageType;
    using pyconv::language::types::line::Line;

    SECTION("Python Line") {
        Line<LanguageType::PYTHON> pythonLine;
        CHECK(pythonLine.languageType() == LanguageType::PYTHON);
    }

    SECTION("Cpp Line") {
        Line<LanguageType::CPP> cppLine;
        CHECK(cppLine.languageType() == LanguageType::CPP);
    }
}
