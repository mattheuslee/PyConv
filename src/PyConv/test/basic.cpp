#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../main/source.hpp"

TEST_CASE( "basic test", "[basic]" ) {
    REQUIRE(pyconv::test() == 1);
}
