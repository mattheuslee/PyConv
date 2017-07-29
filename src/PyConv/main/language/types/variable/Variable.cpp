#include "Variable.hpp"

#include <string>

namespace pyconv {
namespace language {
namespace types {
namespace variable {

Variable& Variable::name(std::string name) {
    name_ = name;
    return *this;
}

std::string Variable::name() {
    return name_;
}

language_t Variable::languageType() {
    return languageType_;
}

Variable& Variable::variableType(variable_t variableType) {
    variableType_ = variableType;
    return *this;
}

variable_t Variable::variableType() {
    return variableType_;
}

}
}
}
}
