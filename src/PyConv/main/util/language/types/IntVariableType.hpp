#pragma once

#include <string>

#include "VariableType.hpp"

namespace pyconv {
namespace util {
namespace language {
namespace types {

class IntVariableType : public VariableType {

public:
    IntVariableType();

    VarType varType();

    std::string str();

private:

protected:

};

}
}
}
}