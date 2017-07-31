#pragma once

#include <string>
#include <tuple>
#include <vector>

#include "main/exception/ConversionException.hpp"
#include "main/util/logging/MLogger.hpp"
#include "main/language/LanguageType.hpp"
#include "main/language/types/line/Line.hpp"
#include "main/language/types/line/LineBase.hpp"
#include "main/language/types/line/LineType.hpp"
#include "main/language/types/line/LineUtil.hpp"
#include "main/language/types/variable/VariableMap.hpp"
#include "main/language/types/variable/VariableType.hpp"
#include "main/language/types/variable/VariableUtil.hpp"
#include "main/parser/Parser.hpp"

namespace pyconv {
namespace converter {

using std::string;
using std::tie;
using std::vector;
using pyconv::exception::ConversionException;
using pyconv::language::LanguageType;
using pyconv::language::types::line::Line;
using pyconv::language::types::line::LineBase;
using pyconv::language::types::line::LineType;
using pyconv::language::types::line::LineUtil;
using pyconv::language::types::variable::VariableMap;
using pyconv::language::types::variable::VariableType;
using pyconv::language::types::variable::VariableUtil;
using pyconv::parser::Parser;

using language_t = LanguageType::language_t;

template<language_t TargetLanguageType = LanguageType::CPP>
class ConverterManager {

public:
    static vector<LineBase> convert(vector<string> filelines) {
        MLogger::logInfo("Converting from python to cpp");
        auto originalLines = vector<Line<LanguageType::PYTHON>>{};
        auto variableMap = VariableMap{};
        tie(originalLines, variableMap) = Parser<LanguageType::PYTHON>::preprocess(filelines);
        auto converted = vector<LineBase>{};
        for (auto line : originalLines) {
            LineBase lineBase;
            converted.push_back(lineBase.line(convertLine_(line, variableMap))
                                        .lineType(line.lineType())
                                        .numWhitespace(line.numWhitespace())
                                        .indentationLevel(line.indentationLevel()));
        }
        return converted;
    }

private:
    static string convertLine_(Line<LanguageType::PYTHON> const & line, VariableMap const & variableMap) {
        if (line.lineType() == LineType::ELIF_STATEMENT) {
            return convertElifStatement_(line.line());
        } else if (line.lineType() == LineType::ELSE_STATEMENT) {
            return convertElseStatement_(line.line());
        } else if (line.lineType() == LineType::FOR_LOOP) {
            return convertForLoop_(line.line());
        } else if (line.lineType() == LineType::IF_STATEMENT) {
            return convertIfStatement_(line.line());
        } else if (line.lineType() == LineType::PRINT_STATEMENT) {
            return convertPrintStatement_(line.line());
        } else if (line.lineType() == LineType::VARIABLE_ASSIGNMENT) {
            return convertVariableAssignment_(line.line());
        } else if (line.lineType() == LineType::VARIABLE_DECLARATION) {
            return convertVariableDeclaration_(line.line(), variableMap);
        } else {
            return "";
        }
    }

    static string convertElifStatement_(string const & line) {
        return "} else if (" + LineUtil<LanguageType::PYTHON>::extractElifCondition(line) + ") {";
    }

    static string convertElseStatement_(string const & line) {
        return "} else {";
    }

    static string convertForLoop_(string const & line) {
        return "for (" + LineUtil<LanguageType::PYTHON>::extractForStatement(line) + ") {";
    }

    static string convertIfStatement_(string const & line) {
        return "if (" + LineUtil<LanguageType::PYTHON>::extractIfCondition(line) + ") {";
    }

    static string convertPrintStatement_(string const & line) {
        return line + ";";
    }

    static string convertVariableAssignment_(string const & line) {
        return line + ";";
    }

    static string convertVariableDeclaration_(string const & line, VariableMap const & variableMap) {
        auto name = VariableUtil<LanguageType::PYTHON>::extractVariableName(line);
        auto assignment = VariableUtil<LanguageType::PYTHON>::extractVariableAssignment(line);
        if (variableMap.find(name).first) {
            return VariableType::variableTypeToString(variableMap.findType(name)) + " " + line + ";";
        } else {
            return VariableType::variableTypeToString(variableMap.findType(assignment)) + " " + line + ";";
        }
    }

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
