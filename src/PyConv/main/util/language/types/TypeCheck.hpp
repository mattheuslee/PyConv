#pragma once

#include "variable/VariableType.hpp"

namespace pyconv {
namespace util {
namespace language {
namespace types {

using variable::VariableType;

class TypeCheck {

public:
    static bool isDoubleVariableType(VariableType const & variableType);
    static bool isIntVariableType(VariableType const & variableType);
    static bool isStringVariableType(VariableType const & variableType);
    static bool isUnknownVariableType(VariableType const & variableType);

private:

protected:

};

}
}
}
}
