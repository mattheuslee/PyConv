#pragma once

#include <algorithm>
#include <string>
#include <vector>

namespace pyconv {
namespace language {
namespace types {
namespace word {

using std::find;
using std::string;
using std::vector;

class ReservedWords {

public:
    static bool isReservedWord(string word);

private:

protected:
    static const vector<string> reservedWords_;

};

}
}
}
}