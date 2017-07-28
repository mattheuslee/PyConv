#include "test/catch.hpp"

#include <string>
#include <vector>

#include "main/file/InputFile.hpp"
#include "main/file/OutputFile.hpp"

using std::string;
using std::vector;

TEST_CASE("OutputFile class") {
    using pyconv::file::InputFile;
    using pyconv::file::OutputFile;

    InputFile inputFile;
    OutputFile outputFile;

    SECTION("Save") {
        vector<string> filelines {
            "",
            "line2",
            "line3    ",
            "    line4",
            "    line5    "
        };
        vector<string> expectedFilelines {
            "",
            "line2",
            "line3",
            "    line4",
            "    line5"
        };
        outputFile.filelines(filelines);
        CHECK(outputFile.save("./src/PyConv/test/testfiles/outputTestFile.txt"));
        CHECK(inputFile.open("./src/PyConv/test/testfiles/outputTestFile.txt"));
        CHECK(inputFile.filelines() == expectedFilelines);
    }

}
