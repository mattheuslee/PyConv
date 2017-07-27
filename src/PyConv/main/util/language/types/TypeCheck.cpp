#include "TypeCheck.hpp"

namespace pyconv {
namespace util {
namespace language {
namespace types {

using variable::VariableType;
using variable::Type;

bool TypeCheck::isDoubleVariableType(VariableType const & variableType) {
    return variableType.type() == Type::DOUBLE;
}

bool TypeCheck::isIntVariableType(VariableType const & variableType) {
    return variableType.type() == Type::INT;
}

bool TypeCheck::isStringVariableType(VariableType const & variableType) {
    return variableType.type() == Type::STRING;
}

bool TypeCheck::isUnknownVariableType(VariableType const & variableType) {
    return variableType.type() == Type::UNKNOWN;
}

}
}
}
}
