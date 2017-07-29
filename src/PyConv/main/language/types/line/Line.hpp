#pragma once

#include <string>

#include "LineType.hpp"
#include "main/language/LanguageType.hpp"

namespace pyconv {
namespace language {
namespace types {
namespace line {

using pyconv::language::LanguageType;

using line_t = pyconv::language::types::line::LineType::line_t;
using language_t = pyconv::language::LanguageType::language_t;

class Line {

public:
    Line& line(std::string line);
    std::string line();

    language_t languageType();

    Line& lineType(line_t lineType);
    line_t lineType();

private:

protected:
    std::string line_;
    language_t languageType_;
    line_t lineType_;

};

}
}
}
}