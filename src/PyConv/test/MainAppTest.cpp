#include "test/catch.hpp"

#include <string>
#include <vector>

#include "main/exception/FileOpenException.hpp"
#include "main/exception/InvalidArgumentException.hpp"
#include "main/MainApp.hpp"

TEST_CASE("MainApp class") {
    using std::string;
    using std::vector;
    using pyconv::exception::FileOpenException;
    using pyconv::exception::InvalidArgumentException;
    using pyconv::MainApp;

    SECTION("Exceptions Thrown") {
        vector<string> args;
        try {
            MainApp mainApp(args);
        } catch (InvalidArgumentException const & e) {
            CHECK(e.message() == "No arguments provided");
        }
        args.push_back("cpp");
        try {
            MainApp mainApp(args);
        } catch (InvalidArgumentException const & e) {
            CHECK(e.message() == "Pairs of input/output files required");
        }
        args.push_back("nonexistingfolder/nonexistingfile.py");
        try {
            MainApp mainApp(args);
        } catch (InvalidArgumentException const & e) {
            CHECK(e.message() == "Pairs of input/output files required");
        }
        args[0] = "java";
        args.push_back("nonexistingfolder/nonexistingfile2.py");
        try {
            MainApp mainApp(args);
        } catch (InvalidArgumentException const & e) {
            CHECK(e.message() == "Invalid language type: java");
        }
    }

    SECTION("No Exceptions Thrown") {
        vector<string> args {"cpp", "./src/PyConv/test/testfiles/properFile.py", "./src/PyConv/test/testfiles/outputFile.cpp"};
        MainApp mainApp(args);
        CHECK_NOTHROW(mainApp.run());
        args[0] = "python";
        mainApp = MainApp(args);
        CHECK_NOTHROW(mainApp.run());
        args[1] = "nonexistingfolder/nonexistingfile.py";
        mainApp = MainApp(args);
        CHECK_NOTHROW(mainApp.run());

    }
}
