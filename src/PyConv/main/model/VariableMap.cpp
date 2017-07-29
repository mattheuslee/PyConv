#include "VariableMap.hpp"

namespace pyconv {
namespace model {

VariableMap::VariableMap() {}

bool VariableMap::add(Variable variable) {
    // Doesn't exist yet
    if (internalMap_.find(variable.name()) == internalMap_.end()) {
        internalMap_[variable.name()] = variable;
        return true;
    } else {
        return false;
    }
}

pair<bool, Variable> VariableMap::find(string name) const {
    // Found
    if (internalMap_.find(name) != internalMap_.end()) {
        return pair<bool, Variable>(true, (internalMap_.find(name))->second);
    } else {
        return pair<bool, Variable>(false, Variable());
    }
}

variable_t VariableMap::findType(string name) const {
    return find(name).second.variableType();
}

}
}
