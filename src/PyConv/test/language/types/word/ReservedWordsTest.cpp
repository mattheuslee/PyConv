#include "test/catch.hpp"

#include "main/language/types/word/ReservedWords.hpp"
#include "main/language/LanguageType.hpp"

TEST_CASE("ReservedWords class") {
    using pyconv::language::LanguageType;
    using pyconv::language::types::word::ReservedWords;

    SECTION("Known python reserved words") {
        CHECK(ReservedWords<LanguageType::PYTHON>::isReservedWord("and"));
        CHECK(ReservedWords<LanguageType::PYTHON>::isReservedWord("as"));
        CHECK(ReservedWords<LanguageType::PYTHON>::isReservedWord("assert"));
        CHECK(ReservedWords<LanguageType::PYTHON>::isReservedWord("break"));
        CHECK(ReservedWords<LanguageType::PYTHON>::isReservedWord("class"));
        CHECK(ReservedWords<LanguageType::PYTHON>::isReservedWord("continue"));
        CHECK(ReservedWords<LanguageType::PYTHON>::isReservedWord("def"));
        CHECK(ReservedWords<LanguageType::PYTHON>::isReservedWord("del"));
        CHECK(ReservedWords<LanguageType::PYTHON>::isReservedWord("elif"));
        CHECK(ReservedWords<LanguageType::PYTHON>::isReservedWord("else"));
        CHECK(ReservedWords<LanguageType::PYTHON>::isReservedWord("except"));
        CHECK(ReservedWords<LanguageType::PYTHON>::isReservedWord("exec"));
        CHECK(ReservedWords<LanguageType::PYTHON>::isReservedWord("finally"));
        CHECK(ReservedWords<LanguageType::PYTHON>::isReservedWord("for"));
        CHECK(ReservedWords<LanguageType::PYTHON>::isReservedWord("from"));
        CHECK(ReservedWords<LanguageType::PYTHON>::isReservedWord("global"));
        CHECK(ReservedWords<LanguageType::PYTHON>::isReservedWord("if"));
        CHECK(ReservedWords<LanguageType::PYTHON>::isReservedWord("import"));
        CHECK(ReservedWords<LanguageType::PYTHON>::isReservedWord("in"));
        CHECK(ReservedWords<LanguageType::PYTHON>::isReservedWord("is"));
        CHECK(ReservedWords<LanguageType::PYTHON>::isReservedWord("lambda"));
        CHECK(ReservedWords<LanguageType::PYTHON>::isReservedWord("not"));
        CHECK(ReservedWords<LanguageType::PYTHON>::isReservedWord("or"));
        CHECK(ReservedWords<LanguageType::PYTHON>::isReservedWord("pass"));
        CHECK(ReservedWords<LanguageType::PYTHON>::isReservedWord("print"));
        CHECK(ReservedWords<LanguageType::PYTHON>::isReservedWord("raise"));
        CHECK(ReservedWords<LanguageType::PYTHON>::isReservedWord("return"));
        CHECK(ReservedWords<LanguageType::PYTHON>::isReservedWord("try"));
        CHECK(ReservedWords<LanguageType::PYTHON>::isReservedWord("while"));
        CHECK(ReservedWords<LanguageType::PYTHON>::isReservedWord("with"));
        CHECK(ReservedWords<LanguageType::PYTHON>::isReservedWord("yield"));
    }

    SECTION("Known python non-reserved words") {
        CHECK_FALSE(ReservedWords<LanguageType::PYTHON>::isReservedWord("test"));
        CHECK_FALSE(ReservedWords<LanguageType::PYTHON>::isReservedWord("demo"));
        CHECK_FALSE(ReservedWords<LanguageType::PYTHON>::isReservedWord("python"));
    }

}
