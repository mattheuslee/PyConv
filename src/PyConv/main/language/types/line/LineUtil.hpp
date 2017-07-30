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

private:

protected:

public:
    static line_t lineType(string line) {
        string firstWord = StringUtil::extractFirstWord(line);
        firstWord = StringUtil::trimTrailingChar(firstWord, ':');
        return LineType::firstWordToLineType(firstWord);
    }

};

}
}
}
}
