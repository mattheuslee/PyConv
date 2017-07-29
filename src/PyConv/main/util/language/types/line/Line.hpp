#pragma once

#include <string>

#include "LineType.hpp"
#include "main/util/language/LanguageType.hpp"

namespace pyconv {
namespace util {
namespace language {
namespace types {
namespace line {

using language_t = pyconv::util::language::LanguageType::language_t;
using pyconv::util::language::LanguageType;

class Line {

public:
    Line& line(std::string line);
    std::string line();

    language_t languageType();

    Line& lineType(LineType lineType);
    LineType lineType();

private:

protected:
    std::string line_;
    language_t languageType_;
    LineType lineType_;

};

}
}
}
}
}
