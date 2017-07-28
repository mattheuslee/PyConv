#include "test/catch.hpp"

#include "main/file/File.hpp"

TEST_CASE("File class") {
    using pyconv::file::File;

    File file;

    SECTION("Open") {
        CHECK_FALSE(file.open("nonexistingfile"));
        CHECK(file.open("./src/PyConv/test/testfiles/python.py"));
    }

    SECTION("File Lines") {
        REQUIRE(file.open("./src/PyConv/test/testfiles/python.py"));
        REQUIRE(file.filelines().size() == 4);
        CHECK(file.filelines()[0] == "import numpy as np");
        CHECK(file.filelines()[1] == "");
        CHECK(file.filelines()[2] == "test");
        CHECK(file.filelines()[3] == "    test");
    }

}
