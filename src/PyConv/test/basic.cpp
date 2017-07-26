#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../main/header.hpp"
#include "../main/source.hpp"

TEST_CASE( "basic test", "[basic]" ) {
    REQUIRE(pyconv::main::hello() == "hello");
    REQUIRE(pyconv::main::test() == 1);
}
