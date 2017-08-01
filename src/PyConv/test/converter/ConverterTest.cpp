#include "test/catch.hpp"

#include <string>
#include <vector>

#include "main/exception/ConversionException.hpp"
#include "main/converter/Converter.hpp"
#include "main/language/LanguageType.hpp"
#include "main/language/types/line/LineType.hpp"
#include "test/TestUtil.hpp"

TEST_CASE("Converter class") {
    using std::string;
    using std::vector;
    using pyconv::converter::Converter;
    using pyconv::exception::ConversionException;
    using pyconv::language::LanguageType;
    using pyconv::language::types::line::LineType;
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

        REQUIRE(convertedLines.size() == TestUtil::SAMPLE_NUM_LINES + 2); // Extra 2 lines for inserted close brace
        auto idx = 0;
        CHECK(convertedLines[idx].line() == "int i = 5;");
        CHECK(convertedLines[idx].languageType() == LanguageType::CPP);
        CHECK(convertedLines[idx].lineType() == LineType::VARIABLE_DECLARATION);
        CHECK(convertedLines[idx].numWhitespace() == 0);
        CHECK(convertedLines[idx].indentationLevel() == 0);

        ++idx;
        CHECK(convertedLines[idx].line() == "i = 10;");
        CHECK(convertedLines[idx].languageType() == LanguageType::CPP);
        CHECK(convertedLines[idx].lineType() == LineType::VARIABLE_ASSIGNMENT);
        CHECK(convertedLines[idx].numWhitespace() == 0);
        CHECK(convertedLines[idx].indentationLevel() == 0);

        ++idx;
        CHECK(convertedLines[idx].line() == "int j = i;");
        CHECK(convertedLines[idx].languageType() == LanguageType::CPP);
        CHECK(convertedLines[idx].lineType() == LineType::VARIABLE_DECLARATION);
        CHECK(convertedLines[idx].numWhitespace() == 0);
        CHECK(convertedLines[idx].indentationLevel() == 0);

        ++idx;
        CHECK(convertedLines[idx].line() == "for (k in {0, 10}) {");
        CHECK(convertedLines[idx].languageType() == LanguageType::CPP);
        CHECK(convertedLines[idx].lineType() == LineType::FOR_LOOP);
        CHECK(convertedLines[idx].numWhitespace() == 0);
        CHECK(convertedLines[idx].indentationLevel() == 0);

        ++idx;
        CHECK(convertedLines[idx].line() == "    if (k == 5) {");
        CHECK(convertedLines[idx].languageType() == LanguageType::CPP);
        CHECK(convertedLines[idx].lineType() == LineType::IF_STATEMENT);
        CHECK(convertedLines[idx].numWhitespace() == 4);
        CHECK(convertedLines[idx].indentationLevel() == 1);

        ++idx;
        CHECK(convertedLines[idx].line() == "        print (\"5!\");");
        CHECK(convertedLines[idx].languageType() == LanguageType::CPP);
        CHECK(convertedLines[idx].lineType() == LineType::PRINT_STATEMENT);
        CHECK(convertedLines[idx].numWhitespace() == 8);
        CHECK(convertedLines[idx].indentationLevel() == 2);

        ++idx;
        CHECK(convertedLines[idx].line() == "    } else if (k == 10) {");
        CHECK(convertedLines[idx].languageType() == LanguageType::CPP);
        CHECK(convertedLines[idx].lineType() == LineType::ELIF_STATEMENT);
        CHECK(convertedLines[idx].numWhitespace() == 4);
        CHECK(convertedLines[idx].indentationLevel() == 1);

        ++idx;
        CHECK(convertedLines[idx].line() == "        print (\"10!\");");
        CHECK(convertedLines[idx].languageType() == LanguageType::CPP);
        CHECK(convertedLines[idx].lineType() == LineType::PRINT_STATEMENT);
        CHECK(convertedLines[idx].numWhitespace() == 8);
        CHECK(convertedLines[idx].indentationLevel() == 2);

        ++idx;
        CHECK(convertedLines[idx].line() == "    } else {");
        CHECK(convertedLines[idx].languageType() == LanguageType::CPP);
        CHECK(convertedLines[idx].lineType() == LineType::ELSE_STATEMENT);
        CHECK(convertedLines[idx].numWhitespace() == 4);
        CHECK(convertedLines[idx].indentationLevel() == 1);

        ++idx;
        CHECK(convertedLines[idx].line() == "        print (\"Not 5 or 10!\");");
        CHECK(convertedLines[idx].languageType() == LanguageType::CPP);
        CHECK(convertedLines[idx].lineType() == LineType::PRINT_STATEMENT);
        CHECK(convertedLines[idx].numWhitespace() == 8);
        CHECK(convertedLines[idx].indentationLevel() == 2);

        ++idx;
        CHECK(convertedLines[idx].line() == "    }");
        CHECK(convertedLines[idx].languageType() == LanguageType::CPP);
        CHECK(convertedLines[idx].lineType() == LineType::CLOSE_BRACE);
        CHECK(convertedLines[idx].numWhitespace() == 0);
        CHECK(convertedLines[idx].indentationLevel() == 1);

        ++idx;
        CHECK(convertedLines[idx].line() == "}");
        CHECK(convertedLines[idx].languageType() == LanguageType::CPP);
        CHECK(convertedLines[idx].lineType() == LineType::CLOSE_BRACE);
        CHECK(convertedLines[idx].numWhitespace() == 0);
        CHECK(convertedLines[idx].indentationLevel() == 0);

        ++idx;
        CHECK(convertedLines[idx].line() == "");
    }
}
