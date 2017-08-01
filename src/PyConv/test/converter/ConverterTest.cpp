#include "test/catch.hpp"

#include <string>
#include <vector>

#include "main/exception/ConversionException.hpp"
#include "main/converter/Converter.hpp"
#include "main/language/LanguageType.hpp"
#include "test/TestUtil.hpp"

TEST_CASE("Converter class") {
    using std::string;
    using std::vector;
    using pyconv::converter::Converter;
    using pyconv::exception::ConversionException;
    using pyconv::language::LanguageType;
    using pyconv::TestUtil;

    SECTION("Convert Throws") {
        auto lines = TestUtil::getSamplePythonLineStrings();

        // Converting from python to python
        CHECK_THROWS_AS(Converter<LanguageType::PYTHON>::convert(lines), ConversionException);

        // Unknown conversion target language
        CHECK_THROWS_AS(Converter<LanguageType::UNKNOWN>::convert(lines), ConversionException);
    }

    SECTION("Convert No Throw") {
        auto lines = TestUtil::getSamplePythonLineStrings();
        auto convertedLines = Converter<LanguageType::CPP>::convert(lines);

        REQUIRE(convertedLines.size() == TestUtil::SAMPLE_NUM_LINES);
        auto idx = 0;
        CHECK(convertedLines[idx].line() == "int i = 5;");

        ++idx;
        CHECK(convertedLines[idx].line() == "i = 10;");

        ++idx;
        CHECK(convertedLines[idx].line() == "int j = i;");

        ++idx;
        CHECK(convertedLines[idx].line() == "for (k in {0, 10}) {");

        ++idx;
        CHECK(convertedLines[idx].line() == "if (k == 5) {");

        ++idx;
        CHECK(convertedLines[idx].line() == "print (\"5!\");");

        ++idx;
        CHECK(convertedLines[idx].line() == "} else if (k == 10) {");

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
