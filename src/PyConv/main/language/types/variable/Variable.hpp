#pragma once

#include <functional>
#include <string>

#include "VariableType.hpp"
#include "main/language/LanguageType.hpp"

namespace pyconv {
namespace language {
namespace types {
namespace variable {

using pyconv::language::LanguageType;

using language_t = LanguageType::language_t;
using variable_t = pyconv::language::types::variable::VariableType::variable_t;

class Variable {

public:
    Variable& name(std::string name);
    std::string name();

    language_t languageType();

    Variable& variableType(variable_t variableType);
    variable_t variableType();

private:

protected:
    std::string name_;
    language_t languageType_;
    variable_t variableType_;

};

struct VariableHash {
    size_t operator()(Variable variable) {
        std::hash<std::string> nameHash;
        return nameHash(variable.name());
    }
};

}
}
}
}
