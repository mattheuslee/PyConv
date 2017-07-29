#include "ReservedWords.hpp"

namespace pyconv {
namespace language {
namespace types {
namespace word {

bool ReservedWords::isReservedWord(string word) {
    return find(reservedWords_.begin(), reservedWords_.end(), word) != reservedWords_.end();
}

}
}
}
}
