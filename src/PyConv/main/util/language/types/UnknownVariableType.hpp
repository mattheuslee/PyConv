#pragma once

#include <string>

#include "VariableType.hpp"

namespace pyconv {
namespace util {
namespace language {
namespace types {

class UnknownVariableType : public VariableType {

public:
    UnknownVariableType();

    VarType varType();

    std::string str();

private:

protected:

};

}
}
}
}