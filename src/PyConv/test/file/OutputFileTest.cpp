#include "test/catch.hpp"

#include <string>
#include <vector>
#include "main/exception/FileOpenException.hpp"
#include "main/file/InputFile.hpp"
#include "main/file/OutputFile.hpp"

TEST_CASE("OutputFile class") {
    using std::string;
    using std::vector;
    using pyconv::exception::FileOpenException;
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
            "    line5",
            ""
        };
        outputFile.filelines(filelines);
        CHECK_NOTHROW(outputFile.save("./src/PyConv/test/testfiles/outputTestFile.txt"));
        CHECK_NOTHROW(inputFile.open("./src/PyConv/test/testfiles/outputTestFile.txt"));
        CHECK(inputFile.filelines() == expectedFilelines);
        CHECK_THROWS_AS(outputFile.save("nonexistingfolder/nonexistingfile.txt"), FileOpenException);
    }

}
