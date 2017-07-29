#pragma once

#include <string>
#include <vector>

#include "main/language/LanguageType.hpp"
#include "main/language/types/line/PythonLine.hpp"

namespace pyconv {
namespace parser {

using std::string;
using std::vector;
using pyconv::language::LanguageType;
using pyconv::language::types::line::PythonLine;

using language_t = LanguageType::language_t;

template<language_t L = LanguageType::PYTHON>
class Parser {

public:
    static vector<PythonLine> process(vector<string> lines) {
        return vector<PythonLine>();
    }

private:

protected:

};

}
}