#include "DoubleVariableType.hpp"

#include <string>

namespace pyconv {
namespace util {
namespace language {
namespace types {

DoubleVariableType::DoubleVariableType() {
    varType_ = VarType::DOUBLE;
}

VarType DoubleVariableType::varType() {
    return varType_;
}

std::string DoubleVariableType::str() {
    return "double";
}

}
}
}
}