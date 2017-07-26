#include "ReservedWords.hpp"

#include <algorithm>
#include <string>

namespace pyconv {
namespace util {
namespace language {
namespace python {

const std::vector<std::string> ReservedWords::reservedWords_ {
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
    "yield" };

const bool ReservedWords::isReservedWord(std::string word) {
    return std::find(reservedWords_.begin(), reservedWords_.end(), word) != reservedWords_.end();
}

}
}
}
}