#pragma once

#include <unordered_map>
#include <utility>

#include "main/language/types/variable/Variable.hpp"
#include "main/language/types/variable/VariableType.hpp"

namespace pyconv {
namespace model {

using std::pair;
using std::string;
using std::unordered_map;
using pyconv::language::types::variable::Variable;
using pyconv::language::types::variable::VariableType;

using variable_t = VariableType::variable_t;

class VariableMap {

public:
    VariableMap();
    bool add(Variable variable);
    pair<bool, Variable> find(string name) const;
    variable_t findType(string name) const;


private:
    unordered_map<string, Variable> internalMap_;

protected:

};

}
}
