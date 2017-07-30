#pragma once

#include <unordered_map>
#include <utility>

#include "main/language/types/variable/VariableBase.hpp"
#include "main/language/types/variable/VariableType.hpp"

namespace pyconv {
namespace language {
namespace types {
namespace variable {

using std::pair;
using std::string;
using std::unordered_map;
using pyconv::language::types::variable::VariableBase;
using pyconv::language::types::variable::VariableType;

using variable_t = VariableType::variable_t;

class VariableMap {

public:
    VariableMap() {}

    bool add(VariableBase variable) {
        // Doesn't exist yet
        if (internalMap_.find(variable.name()) == internalMap_.end()) {
            internalMap_[variable.name()] = variable;
            return true;
        } else {
            return false;
        }
    }

    pair<bool, VariableBase> find(string name) const {
        // Found
        if (internalMap_.find(name) != internalMap_.end()) {
            return pair<bool, VariableBase>(true, (internalMap_.find(name))->second);
        } else {
            return pair<bool, VariableBase>(false, VariableBase());
        }
    }

    variable_t findType(string name) const {
        return find(name).second.variableType();
    }

private:
    unordered_map<string, VariableBase> internalMap_;

protected:

};

}
}
}
}
