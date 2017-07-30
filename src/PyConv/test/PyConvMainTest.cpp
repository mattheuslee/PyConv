#include <string>
#include <vector>

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

#include "main/MainApp.hpp"
#include "main/converter/Converter.hpp"
#include "main/exception/ConversionException.hpp"
#include "main/exception/FileOpenException.hpp"
#include "main/exception/InvalidArgumentException.hpp"
#include "main/file/InputFile.hpp"
#include "main/file/OutputFile.hpp"
#include "main/language/types/variable/VariableBase.hpp"
#include "main/language/types/variable/VariableType.hpp"
#include "main/language/LanguageType.hpp"
#include "main/model/VariableMap.hpp"
#include "main/util/logging/MLogger.hpp"
#include "main/util/StringUtil.hpp"

//#include "InputFileTest.hpp"
//#include "MainAppTest.hpp"
//#include "OutputFileTest.hpp"
//#include "StringUtilTest.hpp"

using std::string;
using std::vector;
using pyconv::converter::Converter;
using pyconv::exception::ConversionException;
using pyconv::language::LanguageType;
using pyconv::language::types::variable::VariableBase;
using pyconv::language::types::variable::VariableType;
using pyconv::model::VariableMap;

using language_t = LanguageType::language_t;

int main(int argc, char* argv[]) {

    MLogger::toCout(true);
    MLogger::filename("./logs/PyConvTest.log");
    MLogger::addLevel(mlogger::info);
    MLogger::addLevel(mlogger::warn);
    MLogger::addLevel(mlogger::error);
    MLogger::addLevel(mlogger::fatal);
    MLogger::init();

    MLogger::logInfo("Starting tests");

    int result = Catch::Session().run(argc, argv);

    MLogger::logInfo("Tests complete");

    return result < 0xff ? result : 0xff;
}

TEST_CASE("ConverterTest class") {
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

TEST_CASE("VariableMapTest class") {
    VariableMap variableMap;

    SECTION("Add") {
        VariableBase variable;
        variable.name("test");
        CHECK(variableMap.add(variable));
        CHECK_FALSE(variableMap.add(variable));
        variable.name("test2");
        CHECK(variableMap.add(variable));
    }

    SECTION("Find") {
        VariableBase variable;
        variable.name("test");
        CHECK_FALSE(variableMap.find(variable.name()).first);
        CHECK(variableMap.add(variable));
        CHECK(variableMap.find(variable.name()).first);
        CHECK(variableMap.find(variable.name()).second.name() == variable.name());
    }

    SECTION("Find Type") {
        VariableBase variable;
        variable.name("test");
        variable.variableType(VariableType::DOUBLE);
        CHECK(variableMap.add(variable));
        CHECK(variableMap.findType("test") == VariableType::DOUBLE);
    }
}
