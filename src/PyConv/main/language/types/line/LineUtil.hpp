#pragma once

#include <string>
#include <vector>

#include "main/language/LanguageType.hpp"
#include "main/language/types/line/Line.hpp"
#include "main/language/types/line/LineType.hpp"
#include "main/util/StringUtil.hpp"

namespace pyconv {
namespace language {
namespace types {
namespace line {

using std::string;
using std::vector;
using pyconv::language::LanguageType;
using pyconv::language::types::line::Line;
using pyconv::language::types::line::LineType;
using pyconv::util::StringUtil;

using language_t = LanguageType::language_t;
using line_t = LineType::line_t;

template <language_t L = LanguageType::PYTHON>
class LineUtil {

public:
    static line_t lineType(string const & line) {
        auto firstWord = StringUtil::extractFirstWord(line);
        firstWord = StringUtil::trimTrailingChar(firstWord, ':');
        return LineType::firstWordToLineType(firstWord);
    }

    static string extractElifCondition(string const & line) {
        auto numChars = LineType::lineTypeToString(LineType::ELIF_STATEMENT).size();
        return StringUtil::trimTrailingChar(StringUtil::trim(line.substr(numChars)), ':');
    }

    static string extractIfCondition(string const & line) {
        auto numChars = LineType::lineTypeToString(LineType::IF_STATEMENT).size();
        return StringUtil::trimTrailingChar(StringUtil::trim(line.substr(numChars)), ':');
    }

    static string extractForStatement(string const & line) {
        auto numChars = LineType::lineTypeToString(LineType::FOR_LOOP).size();
        return StringUtil::trimTrailingChar(StringUtil::trim(line.substr(numChars)), ':');
    }

    static vector<string> toStringVector(vector<Line> const & lines) {
        auto stringVector = vector<string>{};
        for (auto const & line : lines) {
            stringVector.push_back(line.line());
        }
        return stringVector;
    }

private:

protected:

};

}
}
}
}
