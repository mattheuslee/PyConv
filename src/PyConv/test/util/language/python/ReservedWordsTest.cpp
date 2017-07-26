#include "../../../catch.hpp"

#include "../../../../main/util/language/python/ReservedWords.hpp"

TEST_CASE("Python reserved words identified") {
    using pyconv::util::language::python::ReservedWords;

    SECTION("Known reserved words") {
        CHECK(ReservedWords::isReservedWord("and"));
        CHECK(ReservedWords::isReservedWord("as"));
        CHECK(ReservedWords::isReservedWord("assert"));
        CHECK(ReservedWords::isReservedWord("break"));
        CHECK(ReservedWords::isReservedWord("class"));
        CHECK(ReservedWords::isReservedWord("continue"));
        CHECK(ReservedWords::isReservedWord("def"));
        CHECK(ReservedWords::isReservedWord("del"));
        CHECK(ReservedWords::isReservedWord("elif"));
        CHECK(ReservedWords::isReservedWord("else"));
        CHECK(ReservedWords::isReservedWord("except"));
        CHECK(ReservedWords::isReservedWord("exec"));
        CHECK(ReservedWords::isReservedWord("finally"));
        CHECK(ReservedWords::isReservedWord("for"));
        CHECK(ReservedWords::isReservedWord("from"));
        CHECK(ReservedWords::isReservedWord("global"));
        CHECK(ReservedWords::isReservedWord("if"));
        CHECK(ReservedWords::isReservedWord("import"));
        CHECK(ReservedWords::isReservedWord("in"));
        CHECK(ReservedWords::isReservedWord("is"));
        CHECK(ReservedWords::isReservedWord("lambda"));
        CHECK(ReservedWords::isReservedWord("not"));
        CHECK(ReservedWords::isReservedWord("or"));
        CHECK(ReservedWords::isReservedWord("pass"));
        CHECK(ReservedWords::isReservedWord("print"));
        CHECK(ReservedWords::isReservedWord("raise"));
        CHECK(ReservedWords::isReservedWord("return"));
        CHECK(ReservedWords::isReservedWord("try"));
        CHECK(ReservedWords::isReservedWord("while"));
        CHECK(ReservedWords::isReservedWord("with"));
        CHECK(ReservedWords::isReservedWord("yield"));
    }

    SECTION("Known non-reserved words") {
        CHECK_FALSE(ReservedWords::isReservedWord("test"));
        CHECK_FALSE(ReservedWords::isReservedWord("demo"));
        CHECK_FALSE(ReservedWords::isReservedWord("python"));
    }

}

