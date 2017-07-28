#include "test/catch.hpp"

#include <string>
#include <vector>

#include "main/file/InputFile.hpp"
#include "main/util/logging/MLogger.hpp"

using std::string;
using std::vector;

TEST_CASE("InputFile class") {
    using pyconv::file::InputFile;

    InputFile inputFile;

    SECTION("Open") {
        CHECK_FALSE(inputFile.open("nonexistingfolder/nonexistingfile.txt"));
        CHECK(inputFile.open("./src/PyConv/test/testfiles/inputTestFile.txt"));
    }

    SECTION("File Lines") {
        REQUIRE(inputFile.open("./src/PyConv/test/testfiles/inputTestFile.txt"));
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
