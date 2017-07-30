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

class Converter {

public:
    explicit Converter(language_t languageType) {
        languageType_ = languageType;
    }

    vector<LineBase> convert(vector<string> filelines) {
        vector<Line<LanguageType::PYTHON>> originalLines;
        vector<LineBase> convertedLines;
        switch (languageType_) {
        case LanguageType::PYTHON:
            MLogger::logError("Converting from python to python, nothing to be done");
            throw ConversionException("Converting from python to python, nothing to be done");
        case LanguageType::CPP:
            MLogger::logInfo("Converting from python to cpp");
            originalLines = Parser<LanguageType::PYTHON>::process(filelines);
            convertedLines = convertToCpp_(originalLines);
            return convertedLines;
        default:
            MLogger::logError("Unknown language type to convert to");
            throw ConversionException("Unknown language type to convert to");
        }
    }

private:
    language_t languageType_;

    vector<LineBase> convertToCpp_(vector<Line<LanguageType::PYTHON>> pythonLines) {
        vector<Line<LanguageType::CPP>> convertedCpp;
        vector<LineBase> converted;

        for (Line<LanguageType::CPP> const & line : convertedCpp) {
            converted.push_back(line);
        }
        return converted;
    }

protected:

};

}
}
