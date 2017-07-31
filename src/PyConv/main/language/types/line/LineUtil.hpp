#pragma once

#include <string>

#include "main/language/LanguageType.hpp"
#include "main/language/types/line/LineType.hpp"
#include "main/util/StringUtil.hpp"

namespace pyconv {
namespace language {
namespace types {
namespace line {

using pyconv::language::LanguageType;
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

private:

protected:

};

}
}
}
}
