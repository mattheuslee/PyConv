#pragma once

namespace pyconv {
namespace language {
namespace types{
namespace variable {

class VariableType {

public:
    typedef int variable_t;

    static const variable_t DOUBLE = 0;
    static const variable_t INT = 1;
    static const variable_t STRING = 2;
    static const variable_t UNKNOWN = -1;

private:

protected:

};

}
}
}
}
