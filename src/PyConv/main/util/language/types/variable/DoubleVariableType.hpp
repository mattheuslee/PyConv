#pragma once

#include <string>

#include "VariableType.hpp"

namespace pyconv {
namespace util {
namespace language {
namespace types {

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