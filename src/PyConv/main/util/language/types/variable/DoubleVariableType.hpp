#pragma once

#include <string>

#include "VariableType.hpp"

namespace pyconv {
namespace util {
namespace language {
namespace types {
namespace variable {

class DoubleVariableType : public VariableType {

public:
    DoubleVariableType();

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
