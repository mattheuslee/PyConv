#include "IntVariableType.hpp"

#include <string>

namespace pyconv {
namespace util {
namespace language {
namespace types {
namespace variable {

IntVariableType::IntVariableType() {
    varType_ = VarType::INT;
}

VarType IntVariableType::varType() {
    return varType_;
}

std::string IntVariableType::str() {
    return "int";
}

}
}
}
}
}
