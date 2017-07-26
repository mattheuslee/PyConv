#include "StringVariableType.hpp"

#include <string>

namespace pyconv {
namespace util {
namespace language {
namespace types {

StringVariableType::StringVariableType() {
    varType_ = VarType::STRING;
}

VarType StringVariableType::varType() {
    return varType_;
}

std::string StringVariableType::str() {
    return "string";
}

}
}
}
}