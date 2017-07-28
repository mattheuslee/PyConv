#include "Variable.hpp"

#include <string>

namespace pyconv {
namespace util {
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

pyconv::util::language::LanguageType Variable::languageType() {
    return languageType_;
}

Variable& Variable::variableType(VariableType variableType) {
    variableType_ = variableType;
    return *this;
}

VariableType Variable::variableType() {
    return variableType_;
}

}
}
}
}
}
