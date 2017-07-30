#include "test/catch.hpp"

#include <string>
#include <vector>

#include "main/converter/Converter.hpp"
#include "main/exception/ConversionException.hpp"
#include "main/language/LanguageType.hpp"

TEST_CASE("ConverterTest class") {
    using std::string;
    using std::vector;
    using pyconv::converter::Converter;
    using pyconv::exception::ConversionException;
    using pyconv::language::LanguageType;

    SECTION("Convert") {
        Converter converter(LanguageType::PYTHON);
        vector<string> lines {
            "i = 5",
            "if i == 5:",
            "    print \"5!\"",
            "else:",
            "    print \"not 5!\"",
            ""
        };
        CHECK_THROWS_AS(converter.convert(lines), ConversionException); // Converting from python to python

        converter = Converter(LanguageType::UNKNOWN);
        CHECK_THROWS_AS(converter.convert(lines), ConversionException); // Unknown language to convert to

        converter = Converter(LanguageType::CPP);
        CHECK_NOTHROW(converter.convert(lines));
    }
}
