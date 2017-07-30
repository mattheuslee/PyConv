#include "test/catch.hpp"

#include <string>
#include <vector>

#include "main/converter/Converter.hpp"
#include "main/exception/ConversionException.hpp"
#include "main/language/LanguageType.hpp"
#include "test/TestUtil.hpp"

TEST_CASE("ConverterTest class") {
    using std::string;
    using std::vector;
    using pyconv::converter::Converter;
    using pyconv::exception::ConversionException;
    using pyconv::language::LanguageType;
    using pyconv::TestUtil;

    SECTION("Convert") {
        vector<string> lines = TestUtil::getSamplePythonLineStrings();

        CHECK_THROWS_AS(Converter<LanguageType::PYTHON>::convert(lines), ConversionException); // Converting from python to python

        CHECK_THROWS_AS(Converter<LanguageType::UNKNOWN>::convert(lines), ConversionException); // Unknown language to convert to

        CHECK_NOTHROW(Converter<LanguageType::CPP>::convert(lines));
    }
}
