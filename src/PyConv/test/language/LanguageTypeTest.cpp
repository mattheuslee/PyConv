#include <string>

#include "test/catch.hpp"

#include "main/language/LanguageType.hpp"

TEST_CASE("LanguageType") {
    using pyconv::language::LanguageType;

    SECTION("Is Valid Language Type") {
        CHECK(LanguageType::isValidLanguageType(LanguageType::PYTHON));
        CHECK(LanguageType::isValidLanguageType(LanguageType::CPP));
        CHECK_FALSE(LanguageType::isValidLanguageType(LanguageType::UNKNOWN));
        CHECK(LanguageType::isValidLanguageType("python"));
        CHECK(LanguageType::isValidLanguageType("cpp"));
        CHECK_FALSE(LanguageType::isValidLanguageType("java"));
    }

    SECTION("String To Language Type") {
        CHECK(LanguageType::stringToLanguageType("python") == LanguageType::PYTHON);
        CHECK(LanguageType::stringToLanguageType("cpp") == LanguageType::CPP);
        CHECK(LanguageType::stringToLanguageType("java") == LanguageType::UNKNOWN);
    }

    SECTION("Language Type To String") {
        CHECK(LanguageType::languageTypeToString(LanguageType::PYTHON) == "python");
        CHECK(LanguageType::languageTypeToString(LanguageType::CPP) == "cpp");
        CHECK(LanguageType::languageTypeToString(LanguageType::UNKNOWN) == "unknown");
    }
}
