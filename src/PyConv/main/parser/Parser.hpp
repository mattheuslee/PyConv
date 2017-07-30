#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "main/language/LanguageType.hpp"
#include "main/language/types/line/LineType.hpp"
#include "main/language/types/line/LineUtil.hpp"
#include "main/util/StringUtil.hpp"
#include "main/util/logging/MLogger.hpp"

namespace pyconv {
namespace parser {

using std::endl;
using std::ostringstream;
using std::string;
using std::vector;
using pyconv::language::LanguageType;
using pyconv::language::types::line::Line;
using pyconv::language::types::line::LineType;
using pyconv::language::types::line::LineUtil;
using pyconv::util::StringUtil;

using language_t = LanguageType::language_t;

template<language_t L = LanguageType::PYTHON>
class Parser {

private:
    static void printInfo(vector<Line<LanguageType::PYTHON>> const & lines) {
        ostringstream message;
        message << "Processed python lines:" << endl;
        for (Line<LanguageType::PYTHON> const & line : lines) {
            message << "line: " << line.line() << endl
                    << "num whitespace: " << line.numWhitespace()
                    << " indentation level: " << line.indentationLevel()
                    << " line type: " << LineType::lineTypeToString(line.lineType()) << endl;
        }
        MLogger::logInfo(message.str());
    }

    static vector<Line<LanguageType::PYTHON>> initialConstruct_(vector<string> const & lines) {
        vector<Line<LanguageType::PYTHON>> initiallyConstructedLines;
        for (string const & line : lines) {
            initiallyConstructedLines.push_back(constructPythonLine_(line));
        }
        return initiallyConstructedLines;
    }

    static Line<LanguageType::PYTHON> constructPythonLine_(string const & line) {
        Line<LanguageType::PYTHON> pythonLine;
        pythonLine.line(StringUtil::trimLeading(line))
                  .numWhitespace(StringUtil::numLeadingWhitespace(line))
                  .lineType(LineUtil<LanguageType::PYTHON>::lineType(StringUtil::trimLeading(line)));
        return pythonLine;
    }

    static void processIndentationLevels_(vector<Line<LanguageType::PYTHON>> & lines) {
        int prevNumWhitespace = 0;
        int currIndentationLevel = 0;

        for (Line<LanguageType::PYTHON> & line : lines) {
            if (line.numWhitespace() < prevNumWhitespace) {
                --currIndentationLevel;
            } else if (line.numWhitespace() > prevNumWhitespace) {
                ++currIndentationLevel;
            }
            prevNumWhitespace = line.numWhitespace();
            line.indentationLevel(currIndentationLevel);
        }
    }

protected:

public:
    static vector<Line<LanguageType::PYTHON>> process(vector<string> lines) {
        vector<Line<LanguageType::PYTHON>> processedLines = initialConstruct_(lines);
        processIndentationLevels_(processedLines);
        printInfo(processedLines);
        return processedLines;
    }

};

}
}
