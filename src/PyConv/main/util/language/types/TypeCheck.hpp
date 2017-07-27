#pragma once

#include "line/LineType.hpp"
#include "variable/VariableType.hpp"

namespace pyconv {
namespace util {
namespace language {
namespace types {

using variable::VariableType;
using line::LineType;

class TypeCheck {

public:
    static bool isBlankLineType(LineType const & lineType);
    static bool isVariableDeclarationLineType(LineType const & lineType);

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
