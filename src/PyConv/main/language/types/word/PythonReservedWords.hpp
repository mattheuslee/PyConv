#pragma once

#include <string>
#include <vector>

#include "ReservedWords.hpp"

namespace pyconv {
namespace language {
namespace types {
namespace word {

class PythonReservedWords : public ReservedWords {

public:

private:

protected:

};

const vector<string> ReservedWords::reservedWords_ {
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
