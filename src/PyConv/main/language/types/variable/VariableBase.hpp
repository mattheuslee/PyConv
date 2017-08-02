#pragma once

#include <functional>
#include <string>

#include "VariableType.hpp"
#include "main/language/LanguageType.hpp"

namespace pyconv {
namespace language {
namespace types {
namespace variable {

using std::string;
using pyconv::language::LanguageType;

using language_t = LanguageType::language_t;
using variable_t = pyconv::language::types::variable::VariableType::variable_t;

class VariableBase {

public:
    VariableBase() : name_(""), languageType_(LanguageType::UNKNOWN), variableType_(VariableType::UNKNOWN) {}

    VariableBase& name(string name) {
        name_ = name;
        return *this;
    }

    string name() const {
        return name_;
    }

    language_t languageType() const {
        return languageType_;
    }

    VariableBase& variableType(variable_t variableType) {
        variableType_ = variableType;
        return *this;
    }

    variable_t variableType() const {
        return variableType_;
    }

private:

protected:
    std::string name_;
    language_t languageType_;
    variable_t variableType_;

};

}
}
}
}
