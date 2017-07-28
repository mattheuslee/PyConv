#pragma once

#include <string>
#include <vector>

namespace pyconv {
namespace util {
namespace language {
namespace types {
namespace word {

class ReservedWords {

public:
    static bool isReservedWord(std::string word);

private:

protected:
    static const std::vector<std::string> reservedWords_;

};

}
}
}
}
}
