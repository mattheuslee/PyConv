#include "VariableType.hpp"

namespace pyconv {
namespace util {
namespace language {
namespace types {
namespace variable {

Type VariableType::type() {
    return type_;
}

std::string VariableType::str() {
    return name_;
}

}
}
}
}
}
