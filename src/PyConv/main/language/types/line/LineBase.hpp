#pragma once

#include <string>

#include "LineType.hpp"
#include "main/language/LanguageType.hpp"

namespace pyconv {
namespace language {
namespace types {
namespace line {

using std::string;
using pyconv::language::LanguageType;
using pyconv::language::types::line::LineType;

using line_t = LineType::line_t;
using language_t = LanguageType::language_t;

class LineBase {

private:

protected:
    std::string line_;
    language_t languageType_;
    line_t lineType_;

    int numWhitespace_;
    int indentationLevel_;

public:
    LineBase() : line_(""), languageType_(LanguageType::UNKNOWN), lineType_(LineType::UNKNOWN),
                 numWhitespace_(0), indentationLevel_(0) {}

    LineBase& line(string line) {
        line_ = line;
        return *this;
    }

    string line() const {
        return line_;
    }

    language_t languageType() const {
        return languageType_;
    }

    LineBase& lineType(line_t lineType) {
        lineType_ = lineType;
        return *this;
    }

    line_t lineType() const {
        return lineType_;
    }

    LineBase& numWhitespace(int numWhitespace) {
        numWhitespace_ = numWhitespace;
        return *this;
    }

    int numWhitespace() const {
        return numWhitespace_;
    }

    LineBase& indentationLevel(int indentationLevel) {
        indentationLevel_ = indentationLevel;
        return *this;
    }

    int indentationLevel() const {
        return indentationLevel_;
    }

};

}
}
}
}
