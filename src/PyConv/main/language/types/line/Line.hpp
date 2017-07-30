#pragma once

#include <string>

#include "LineBase.hpp"
#include "main/language/LanguageType.hpp"

namespace pyconv {
namespace language {
namespace types {
namespace line {

using pyconv::language::LanguageType;

using language_t = pyconv::language::LanguageType::language_t;

template<language_t L = LanguageType::PYTHON>
class Line : public LineBase {

public:
    Line() : LineBase() {
        languageType_ = LanguageType::PYTHON;
    }

private:

protected:

};

template<>
class Line<LanguageType::CPP> : public LineBase {

public:
    Line() : LineBase() {
        languageType_ = LanguageType::CPP;
    }


private:

protected:

};

}
}
}
}
