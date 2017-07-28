#include "PythonVariable.hpp"

#include <string>

namespace pyconv {
namespace util {
namespace language {
namespace types {
namespace variable {

PythonVariable::PythonVariable() {
    languageType_ = pyconv::util::language::LanguageType::PYTHON;
    variableType_ = VariableType::UNKNOWN;
}

}
}
}
}
}
