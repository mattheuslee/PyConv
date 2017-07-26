#include "UnknownVariableType.hpp"

#include <string>

namespace pyconv {
namespace util {
namespace language {
namespace types {
namespace variable {

UnknownVariableType::UnknownVariableType() {
    varType_ = VarType::UNKNOWN;
}

VarType UnknownVariableType::varType() {
    return varType_;
}

std::string UnknownVariableType::str() {
    return "unknown";
}

}
}
}
}
}
