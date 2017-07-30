#pragma once

#include <functional>
#include <string>

#include "VariableBase.hpp"
#include "main/language/LanguageType.hpp"

namespace pyconv {
namespace language {
namespace types {
namespace variable {

using pyconv::language::LanguageType;

using language_t = LanguageType::language_t;

template <language_t L = LanguageType::PYTHON>
class Variable : public VariableBase {

public:
    Variable() : VariableBase() {
        languageType_ = LanguageType::PYTHON;
    }

private:

protected:

};

template<>
class Variable<LanguageType::CPP> : public VariableBase {

public:
    Variable() : VariableBase() {
        languageType_ = LanguageType::CPP;
    }

private:

protected:

};

}
}
}
}
