#include "PythonLine.hpp"

#include <string>

namespace pyconv {
namespace language {
namespace types {
namespace line {

PythonLine::PythonLine() : Line() {
    languageType_ = LanguageType::PYTHON;
    lineType_ = LineType::UNKNOWN;
}

}
}
}
}
