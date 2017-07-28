#include "PythonReservedWords.hpp"

#include <algorithm>

namespace pyconv {
namespace util {
namespace language {
namespace types {
namespace word {

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
    "yield"
};

}
}
}
}
}
