#pragma once

#include <string>

#include "LineType.hpp"
#include "main/util/language/LanguageType.hpp"

namespace pyconv {
namespace util {
namespace language {
namespace types {
namespace line {

class Line {

public:
    Line& line(std::string line);
    std::string line();

    pyconv::util::language::LanguageType languageType();

    Line& lineType(LineType lineType);
    LineType lineType();

private:

protected:
    std::string line_;
    pyconv::util::language::LanguageType languageType_;
    LineType lineType_;

};

}
}
}
}
}
