#pragma once

#include <string>
#include <vector>

#include "main/util/logging/MLogger.hpp"
#include "main/language/LanguageType.hpp"
#include "main/language/types/line/Line.hpp"
#include "main/language/types/line/PythonLine.hpp"

namespace pyconv {
namespace converter {

using std::string;
using std::vector;
using pyconv::language::LanguageType;
using pyconv::language::types::line::Line;
using pyconv::language::types::line::LineType;
using pyconv::language::types::line::PythonLine;

class Converter {

public:
    explicit Converter(int languageType);

    bool convert(vector<string> filelines);

private:
    int languageType_;

protected:

};

}
}
