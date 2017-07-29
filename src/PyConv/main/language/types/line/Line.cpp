#include "Line.hpp"

#include <string>

namespace pyconv {
namespace language {
namespace types {
namespace line {

Line& Line::line(std::string line) {
    line_ = line;
    return *this;
}

std::string Line::line() {
    return line_;
}

language_t Line::languageType() {
    return languageType_;
}

Line& Line::lineType(line_t lineType) {
    lineType_ = lineType;
    return *this;
}

line_t Line::lineType() {
    return lineType_;
}

}
}
}
}
