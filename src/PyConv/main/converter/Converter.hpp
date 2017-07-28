#pragma once

#include <string>
#include <vector>

#include "main/util/language/LanguageType.hpp"
#include "main/util/logging/MLogger.hpp"

namespace pyconv {
namespace converter {

using std::string;
using std::vector;
using pyconv::util::language::LanguageType;

class Converter {

public:
    Converter(LanguageType languageType);

    bool convert(vector<string> filelines);

private:
    LanguageType languageType_;

protected:

};

}
}
