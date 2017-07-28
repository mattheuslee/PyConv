#include "test/catch.hpp"

#include "main/file/File.hpp"

TEST_CASE("File class") {
    using pyconv::file::File;

    File file;

    SECTION("Open") {
        CHECK_FALSE(file.open("nonexistingfile"));
        CHECK(file.open("./src/PyConv/test/data/testFile.py"));
    }

}
