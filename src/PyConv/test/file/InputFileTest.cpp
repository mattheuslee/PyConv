#include "test/catch.hpp"

#include <string>
#include <vector>
#include "main/exception/FileOpenException.hpp"
#include "main/file/InputFile.hpp"

TEST_CASE("InputFile class") {
    using std::string;
    using std::vector;
    using pyconv::exception::FileOpenException;
    using pyconv::file::InputFile;

    InputFile inputFile;

    SECTION("Open") {
        CHECK_THROWS_AS(inputFile.open("nonexistingfolder/nonexistingfile.txt"), FileOpenException);
        CHECK_NOTHROW(inputFile.open("./src/PyConv/test/testfiles/inputTestFile.txt"));
    }

    SECTION("File Lines") {
        REQUIRE_NOTHROW(inputFile.open("./src/PyConv/test/testfiles/inputTestFile.txt"));
        vector<string> expectedFilelines {
            "",
            "line2",
            "line3",
            "    line4",
            "    line5"
        };
        CHECK(inputFile.filelines() == expectedFilelines);
    }

}
