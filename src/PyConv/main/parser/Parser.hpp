#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include "main/language/LanguageType.hpp"
#include "main/language/types/line/Line.hpp"
#include "main/language/types/line/LineType.hpp"
#include "main/language/types/line/LineUtil.hpp"
#include "main/language/types/variable/Variable.hpp"
#include "main/language/types/variable/VariableMap.hpp"
#include "main/language/types/variable/VariableType.hpp"
#include "main/language/types/variable/VariableUtil.hpp"
#include "main/util/StringUtil.hpp"
#include "main/util/logging/MLogger.hpp"

namespace pyconv {
namespace parser {

using std::endl;
using std::make_pair;
using std::ostringstream;
using std::pair;
using std::string;
using std::vector;
using pyconv::language::LanguageType;
using pyconv::language::types::line::Line;
using pyconv::language::types::line::LineType;
using pyconv::language::types::line::LineUtil;
using pyconv::language::types::variable::Variable;
using pyconv::language::types::variable::VariableMap;
using pyconv::language::types::variable::VariableType;
using pyconv::language::types::variable::VariableUtil;
using pyconv::util::StringUtil;

using language_t = LanguageType::language_t;

template<language_t L = LanguageType::PYTHON>
class Parser {

public:
    static pair<vector<Line>, VariableMap> preprocess(vector<string> const & lines) {
        auto processedLines = initialConstruct_(lines);
        processIndentationLevels_(processedLines);
        processVariableDeclarationAndAssigment_(processedLines);
        auto variableMap = parseVariables_(processedLines);
        printInfo(processedLines);
        return make_pair(processedLines, variableMap);
    }

private:
    static void printInfo(vector<Line> const & lines) {
        ostringstream message;
        message << "Processed python lines:" << endl;
        for (auto const & line : lines) {
            message << "line: " << line.line() << endl
                    << "num whitespace: " << line.numWhitespace()
                    << " indentation level: " << line.indentationLevel()
                    << " line type: " << LineType::lineTypeToString(line.lineType()) << endl;
        }
        MLogger::logInfo(message.str());
    }

    static void printVariableAdded(Variable<LanguageType::PYTHON> const & variable) {
        ostringstream message;
        message << "New python variable:" << endl
                << "Name: " << variable.name()
                << " Type: " << VariableType::variableTypeToString(variable.variableType());
        MLogger::logInfo(message.str());
    }

    static vector<Line> initialConstruct_(vector<string> const & lines) {
        vector<Line> initiallyConstructedLines;
        for (auto const & line : lines) {
            initiallyConstructedLines.push_back(constructPythonLine_(line));
        }
        return initiallyConstructedLines;
    }

    static Line constructPythonLine_(string const & line) {
        Line pythonLine;
        pythonLine.line(StringUtil::trimLeading(line))
                  .numWhitespace(StringUtil::numLeadingWhitespace(line))
                  .languageType(LanguageType::PYTHON)
                  .lineType(LineUtil<LanguageType::PYTHON>::lineType(StringUtil::trimLeading(line)));
        return pythonLine;
    }

    static void processIndentationLevels_(vector<Line> & lines) {
        // TODO figure out better way to handle this
        auto whitespacePerTab = 4;
        for (auto & line : lines) {
            line.indentationLevel(line.numWhitespace() / whitespacePerTab);
        }
        /*auto prevNumWhitespace = 0;
        auto currIndentationLevel = 0;
        for (auto & line : lines) {
            if (line.numWhitespace() < prevNumWhitespace) {
                --currIndentationLevel;
            } else if (line.numWhitespace() > prevNumWhitespace) {
                ++currIndentationLevel;
            }
            prevNumWhitespace = line.numWhitespace();
            line.indentationLevel(currIndentationLevel);
        }*/
    }

    static void processVariableDeclarationAndAssigment_(vector<Line> & lines) {
        VariableMap variableMap;
        for (auto & line : lines) {
            if (line.lineType() == LineType::VARIABLE) {
                Variable<LanguageType::PYTHON> variable;
                string variableName = StringUtil::extractFirstWord(line.line());
                if (!variableMap.find(variableName).first) {
                    line.lineType(LineType::VARIABLE_DECLARATION);
                    variableMap.add(variable.name(variableName));
                } else {
                    line.lineType(LineType::VARIABLE_ASSIGNMENT);
                }
            }
        }
    }

    static VariableMap parseVariables_(vector<Line> const & lines) {
        auto variableMap = VariableMap{};
        for (auto const & line : lines) {
            if (line.lineType() == LineType::VARIABLE_DECLARATION) {
                auto variable = Variable<LanguageType::PYTHON>{};
                variable.name(VariableUtil<LanguageType::PYTHON>::extractVariableName(line.line()));
                auto assignment = VariableUtil<LanguageType::PYTHON>::extractVariableAssignment(line.line());
                if (!variableMap.find(assignment).first) {
                    variable.variableType(VariableUtil<LanguageType::PYTHON>::getVariableType(assignment));
                    variableMap.add(variable);
                    printVariableAdded(variable);
                }
            }
        }
        return variableMap;
    }

protected:

};

}
}
