#include "PythonVariable.hpp"

#include <string>

namespace pyconv {
namespace language {
namespace types {
namespace variable {

PythonVariable::PythonVariable() {
    languageType_ = LanguageType::PYTHON;
    variableType_ = VariableType::UNKNOWN;
}

}
}
}
}
