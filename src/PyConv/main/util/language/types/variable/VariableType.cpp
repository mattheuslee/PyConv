#include "VariableType.hpp"

namespace pyconv {
namespace util {
namespace language {
namespace types {
namespace variable {

Type VariableType::type() const {
    return type_;
}

std::string VariableType::str() const {
    return name_;
}

}
}
}
}
}
