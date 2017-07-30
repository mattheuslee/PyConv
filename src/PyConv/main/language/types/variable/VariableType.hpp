#pragma once

#include <string>

namespace pyconv {
namespace language {
namespace types {
namespace variable {

using std::string;

class VariableType {

public:
    typedef int variable_t;

    static const variable_t DOUBLE = 0;
    static const variable_t INT = 1;
    static const variable_t STRING = 2;
    static const variable_t UNKNOWN = -1;

    static string variableTypeToString(variable_t const & variableType) {
        switch(variableType) {
        case DOUBLE:
            return "double";
        case INT:
            return "int";
        case STRING:
            return "string";
        case UNKNOWN:
        default:
            return "unknown";
        }
    }

    static variable_t stringToVariableType(string const & variableType) {
        if (variableType == "double") {
            return VariableType::DOUBLE;
        } else if (variableType == "int") {
            return VariableType::INT;
        } else if (variableType == "string") {
            return VariableType::STRING;
        }
        return VariableType::UNKNOWN;
    }

private:

protected:

};

}
}
}
}
