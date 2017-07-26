#pragma once

#include <string>

#include "VariableType.hpp"

namespace pyconv {
namespace util {
namespace language {
namespace types {
namespace variable {

class StringVariableType : public VariableType {

public:
    StringVariableType();

    VarType varType();

    std::string str();

private:

protected:

};

}
}
}
}
}
