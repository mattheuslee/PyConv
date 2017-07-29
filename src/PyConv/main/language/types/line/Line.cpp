#include "Line.hpp"

#include <string>

namespace pyconv {
namespace language {
namespace types {
namespace line {

Line::Line() {
    line_ = "";
    languageType_ = LanguageType::UNKNOWN;
    lineType_ = LineType::UNKNOWN;
    numWhitespace_ = 0;
    indentationLevel_ = 0;
}

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

Line& Line::numWhitespace(int numWhitespace) {
    numWhitespace_ = numWhitespace;
    return *this;
}

int Line::numWhitespace() {
    return numWhitespace_;
}

Line& Line::indentationLevel(int indentationLevel) {
    indentationLevel_ = indentationLevel;
    return *this;
}

int Line::indentationLevel() {
    return indentationLevel_;
}

}
}
}
}
