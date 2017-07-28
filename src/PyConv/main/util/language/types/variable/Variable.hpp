#pragma once

#include <functional>
#include <string>

#include "VariableType.hpp"
#include "main/util/language/LanguageType.hpp"

namespace pyconv {
namespace util {
namespace language {
namespace types {
namespace variable {

class Variable {

public:
    Variable& name(std::string name);
    std::string name();

    pyconv::util::language::LanguageType languageType();

    Variable& variableType(VariableType variableType);
    VariableType variableType();

private:

protected:
    std::string name_;
    pyconv::util::language::LanguageType languageType_;
    VariableType variableType_;

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
}
