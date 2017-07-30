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
class Converter {

public:
    static vector<LineBase> convert(vector<string> filelines) {
        MLogger::logInfo("Converting from python to cpp");
        vector<Line<LanguageType::PYTHON>> originalLines = Parser<LanguageType::PYTHON>::process(filelines);
        vector<LineBase> convertedLines = convert_(originalLines);
        return convertedLines;
    }

private:
    static vector<LineBase> convert_(vector<Line<LanguageType::PYTHON>> pythonLines) {
        vector<LineBase> converted;

        return converted;
    }

protected:

};

template<>
class Converter<LanguageType::PYTHON> {

public:
    static vector<LineBase> convert(vector<string> filelines) {
        MLogger::logError("Converting from python to python, nothing to be done");
        throw ConversionException("Converting from python to python, nothing to be done");
    }

private:

protected:

};

template<>
class Converter<LanguageType::UNKNOWN> {

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
