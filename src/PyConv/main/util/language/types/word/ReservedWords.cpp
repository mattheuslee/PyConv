#include "ReservedWords.hpp"

#include <algorithm>

namespace pyconv {
namespace util {
namespace language {
namespace types {
namespace word {

bool ReservedWords::isReservedWord(std::string word) {
    return std::find(reservedWords_.begin(), reservedWords_.end(), word) != reservedWords_.end();
}

}
}
}
}
}
