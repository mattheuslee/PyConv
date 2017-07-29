#pragma once

#include <string>
#include <vector>

#include "main/util/logging/MLogger.hpp"
#include "main/language/LanguageType.hpp"
#include "main/language/types/line/Line.hpp"
#include "main/language/types/line/PythonLine.hpp"
#include "main/parser/Parser.hpp"

namespace pyconv {
namespace converter {

using std::string;
using std::vector;
using pyconv::language::LanguageType;
using pyconv::language::types::line::Line;
using pyconv::language::types::line::LineType;
using pyconv::language::types::line::PythonLine;
using pyconv::parser::Parser;

using language_t = LanguageType::language_t;

class Converter {

public:
    explicit Converter(language_t languageType);

    bool convert(vector<string> filelines);

private:
    language_t languageType_;

protected:

};

}
}
