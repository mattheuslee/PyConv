#pragma once

#include <string>
#include <vector>

namespace pyconv {
namespace util {
namespace language {
namespace python {

    class ReservedWords {

    public:
        static const bool isReservedWord(std::string word);

    private:
        static const std::vector<std::string> reservedWords_;

    };

}
}
}
}