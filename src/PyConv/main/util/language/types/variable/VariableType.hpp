#pragma once

#include <string>

namespace pyconv {
namespace util {
namespace language {
namespace types {
namespace variable {

enum VarType {
    INT,
    DOUBLE,
    STRING,
    UNKNOWN
};

class VariableType {

public:
    virtual VarType varType() = 0;

    virtual std::string str() = 0;

private:

protected:
    VarType varType_;

};

}
}
}
}
}
