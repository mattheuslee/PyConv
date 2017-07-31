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

    SECTION("Convert") {
        vector<string> lines = TestUtil::getSamplePythonLineStrings();

        // Converting from python to python
        CHECK_THROWS_AS(ConverterManager<LanguageType::PYTHON>::convert(lines), ConversionException);

        // Unknown conversion target language
        CHECK_THROWS_AS(ConverterManager<LanguageType::UNKNOWN>::convert(lines), ConversionException);

        CHECK_NOTHROW(ConverterManager<LanguageType::CPP>::convert(lines));
    }
}
