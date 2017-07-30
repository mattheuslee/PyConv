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

    using language_t = LanguageType::language_t;

    SECTION("Convert") {
        Converter converter(LanguageType::PYTHON);
        vector<string> lines {
            "",
            "elif i equals 4:",
            "else",
            "for i in list",
            "if i equals 4:",
            "print i",
             "s = \"hello\""
        };
        CHECK_THROWS_AS(converter.convert(lines), ConversionException); // Converting from python to python

        converter = Converter(LanguageType::UNKNOWN);
        CHECK_THROWS_AS(converter.convert(lines), ConversionException); // Unknown language to convert to

        converter = Converter(LanguageType::CPP);
        CHECK_NOTHROW(converter.convert(lines));
    }
}
