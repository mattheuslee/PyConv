#pragma once

#include <algorithm>
#include <string>
#include <vector>

#include "main/language/LanguageType.hpp"

namespace pyconv {
namespace language {
namespace types {
namespace word {

using std::find;
using std::string;
using std::vector;
using pyconv::language::LanguageType;

using language_t = LanguageType::language_t;

template<language_t L = LanguageType::PYTHON>
class ReservedWords {

private:
    static vector<string> initReservedWords_() {
        vector<string> temp {
            "and",
            "as",
            "assert",
            "break",
            "class",
            "continue",
            "def",
            "del",
            "elif",
            "else",
            "except",
            "exec",
            "finally",
            "for",
            "from",
            "global",
            "if",
            "import",
            "in",
            "is",
            "lambda",
            "not",
            "or",
            "pass",
            "print",
            "raise",
            "return",
            "try",
            "while",
            "with",
            "yield"
        };
        return temp;
    }

protected:

public:
    static bool isReservedWord(string word) {
        static vector<string> reservedWords;
        if (reservedWords.size() == 0) {
            reservedWords = initReservedWords_();
        }
        return find(reservedWords.begin(), reservedWords.end(), word) != reservedWords.end();
    }

};

}
}
}
}
