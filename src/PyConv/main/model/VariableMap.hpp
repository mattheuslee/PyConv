#pragma once

#include <unordered_map>
#include <utility>

#include "main/util/language/types/variable/Variable.hpp"
#include "main/util/language/types/variable/VariableType.hpp"

namespace pyconv {
namespace model {

using std::pair;
using std::string;
using std::unordered_map;
using pyconv::util::language::types::variable::Variable;
using pyconv::util::language::types::variable::VariableType;

class VariableMap {

public:
    VariableMap();
    bool add(Variable variable);
    pair<bool, Variable> find(string name);
    VariableType findType(string name);


private:
    unordered_map<string, Variable> internalMap_;

protected:

};

}
}
