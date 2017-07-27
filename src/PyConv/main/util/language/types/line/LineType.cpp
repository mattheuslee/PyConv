#include "LineType.hpp"

namespace pyconv {
namespace util {
namespace language {
namespace types {
namespace line {

Type LineType::type() const {
    return type_;
}

std::string LineType::str() const {
    return name_;
}

}
}
}
}
}
