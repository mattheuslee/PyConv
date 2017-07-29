#include "test/catch.hpp"

#include <string>
#include <vector>

#include "main/converter/Converter.hpp"
#include "main/language/LanguageType.hpp"

TEST_CASE("ConverterTest class") {
    using std::string;
    using std::vector;
    using pyconv::converter::Converter;
    using pyconv::language::LanguageType;

    using language_t = LanguageType::language_t;

    SECTION("Convert") {
        Converter converter(LanguageType::PYTHON);
        vector<string> lines {"i = 5", "s = \"hello\""};
        CHECK_FALSE(converter.convert(lines)); // No point converting from python to python

        converter = Converter(LanguageType::UNKNOWN);
        CHECK_FALSE(converter.convert(lines)); // Unknown language to convert to

        converter = Converter(LanguageType::CPP);
        CHECK(converter.convert(lines));
    }

}
