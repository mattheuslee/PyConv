#include "test/catch.hpp"

#include <string>
#include <vector>

#include "main/exception/ConversionException.hpp"
#include "main/converter/ConverterManager.hpp"
#include "main/language/LanguageType.hpp"
#include "test/TestUtil.hpp"

TEST_CASE("ConverterManager class") {
    using std::string;
    using std::vector;
    using pyconv::converter::ConverterManager;
    using pyconv::exception::ConversionException;
    using pyconv::language::LanguageType;
    using pyconv::TestUtil;

    SECTION("Convert Throws") {
        auto lines = TestUtil::getSamplePythonLineStrings();

        // Converting from python to python
        CHECK_THROWS_AS(ConverterManager<LanguageType::PYTHON>::convert(lines), ConversionException);

        // Unknown conversion target language
        CHECK_THROWS_AS(ConverterManager<LanguageType::UNKNOWN>::convert(lines), ConversionException);
    }

    SECTION("Convert No Throw") {
        auto lines = TestUtil::getSamplePythonLineStrings();
        auto convertedLines = ConverterManager<LanguageType::CPP>::convert(lines);

        REQUIRE(convertedLines.size() == TestUtil::SAMPLE_NUM_LINES);
        auto idx = 0;
        CHECK(convertedLines[idx].line() == "int i = 5;");

        ++idx;
        CHECK(convertedLines[idx].line() == "i = 10;");

        ++idx;
        CHECK(convertedLines[idx].line() == "int j = i;");

        ++idx;
        CHECK(convertedLines[idx].line() == "if (i == 5) {");

        ++idx;
        CHECK(convertedLines[idx].line() == "print (\"5!\");");

        ++idx;
        CHECK(convertedLines[idx].line() == "} else if (i == 10) {");

        ++idx;
        CHECK(convertedLines[idx].line() == "print (\"10!\");");

        ++idx;
        CHECK(convertedLines[idx].line() == "} else {");

        ++idx;
        CHECK(convertedLines[idx].line() == "print (\"Not 5 or 10!\");");

        ++idx;
        CHECK(convertedLines[idx].line() == "");
    }
}
