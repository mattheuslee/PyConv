#include "../../../catch.hpp"

#include "../../../../main/util/language/python/ReservedWords.hpp"

TEST_CASE("Python reserved words identified") {
    using pyconv::util::language::python::ReservedWords;

    SECTION("Known reserved words") {
        REQUIRE(ReservedWords::isReservedWord("and"));
        REQUIRE(ReservedWords::isReservedWord("as"));
        REQUIRE(ReservedWords::isReservedWord("assert"));
        REQUIRE(ReservedWords::isReservedWord("break"));
        REQUIRE(ReservedWords::isReservedWord("class"));
        REQUIRE(ReservedWords::isReservedWord("continue"));
        REQUIRE(ReservedWords::isReservedWord("def"));
        REQUIRE(ReservedWords::isReservedWord("del"));
        REQUIRE(ReservedWords::isReservedWord("elif"));
        REQUIRE(ReservedWords::isReservedWord("else"));
        REQUIRE(ReservedWords::isReservedWord("except"));
        REQUIRE(ReservedWords::isReservedWord("exec"));
        REQUIRE(ReservedWords::isReservedWord("finally"));
        REQUIRE(ReservedWords::isReservedWord("for"));
        REQUIRE(ReservedWords::isReservedWord("from"));
        REQUIRE(ReservedWords::isReservedWord("global"));
        REQUIRE(ReservedWords::isReservedWord("if"));
        REQUIRE(ReservedWords::isReservedWord("import"));
        REQUIRE(ReservedWords::isReservedWord("in"));
        REQUIRE(ReservedWords::isReservedWord("is"));
        REQUIRE(ReservedWords::isReservedWord("lambda"));
        REQUIRE(ReservedWords::isReservedWord("not"));
        REQUIRE(ReservedWords::isReservedWord("or"));
        REQUIRE(ReservedWords::isReservedWord("pass"));
        REQUIRE(ReservedWords::isReservedWord("print"));
        REQUIRE(ReservedWords::isReservedWord("raise"));
        REQUIRE(ReservedWords::isReservedWord("return"));
        REQUIRE(ReservedWords::isReservedWord("try"));
        REQUIRE(ReservedWords::isReservedWord("while"));
        REQUIRE(ReservedWords::isReservedWord("with"));
        REQUIRE(ReservedWords::isReservedWord("yield"));
    }

    SECTION("Known non-reserved words") {
        REQUIRE(!ReservedWords::isReservedWord("test"));
        REQUIRE(!ReservedWords::isReservedWord("demo"));
        REQUIRE(!ReservedWords::isReservedWord("python"));
    }

}

