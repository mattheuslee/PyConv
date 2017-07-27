#include "TypeCheck.hpp"

namespace pyconv {
namespace util {
namespace language {
namespace types {

using variable::VariableType;
using line::LineType;

bool TypeCheck::isBlankLineType(LineType const & lineType) {
    return lineType.type() == line::Type::BLANK;
}

bool TypeCheck::isVariableDeclarationLineType(LineType const & lineType) {
    return lineType.type() == line::Type::VARIABLE_DECLARATION;
}

bool TypeCheck::isDoubleVariableType(VariableType const & variableType) {
    return variableType.type() == variable::Type::DOUBLE;
}

bool TypeCheck::isIntVariableType(VariableType const & variableType) {
    return variableType.type() == variable::Type::INT;
}

bool TypeCheck::isStringVariableType(VariableType const & variableType) {
    return variableType.type() == variable::Type::STRING;
}

bool TypeCheck::isUnknownVariableType(VariableType const & variableType) {
    return variableType.type() == variable::Type::UNKNOWN;
}

}
}
}
}
