#pragma once

#include <string>
#include <vector>

#include "main/exception/ConversionException.hpp"
#include "main/util/logging/MLogger.hpp"
#include "main/language/LanguageType.hpp"
#include "main/language/types/line/Line.hpp"
#include "main/language/types/line/LineBase.hpp"
#include "main/language/types/line/LineType.hpp"
#include "main/parser/Parser.hpp"

namespace pyconv {
namespace converter {

using std::string;
using std::vector;
using pyconv::exception::ConversionException;
using pyconv::language::LanguageType;
using pyconv::language::types::line::Line;
using pyconv::language::types::line::LineBase;
using pyconv::language::types::line::LineType;
using pyconv::parser::Parser;

using language_t = LanguageType::language_t;

template<language_t TargetLanguageType = LanguageType::CPP>
class ConverterManager {

public:
    static vector<LineBase> convert(vector<string> filelines) {
        MLogger::logInfo("Converting from python to cpp");
        auto originalLines = Parser<LanguageType::PYTHON>::preProcess(filelines);
        auto variableMap = Parser<LanguageType::PYTHON>::parseVariables(originalLines);
        auto converted = vector<LineBase>{};
        return converted;
    }

private:

protected:

};

template<>
class ConverterManager<LanguageType::PYTHON> {

public:
    static vector<LineBase> convert(vector<string> filelines) {
        MLogger::logError("Converting from python to python, nothing to be done");
        throw ConversionException("Converting from python to python, nothing to be done");
    }

private:

protected:

};

template<>
class ConverterManager<LanguageType::UNKNOWN> {

public:
    static vector<LineBase> convert(vector<string> filelines) {
        MLogger::logError("Unknown language type to convert to");
        throw ConversionException("Unknown language type to convert to");
    }

private:

protected:

};

}
}
