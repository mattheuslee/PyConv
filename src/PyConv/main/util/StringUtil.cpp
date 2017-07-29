#include "StringUtil.hpp"

namespace pyconv {
namespace util {

string StringUtil::trim(string const & s) {
    return trimTrailing(trimLeading(s));
}

string StringUtil::trimLeading(string const & s) {
    auto it = s.begin();
    while (it != s.end() && isspace(*it)) {
        it++;
    }
    return string(it, s.rbegin().base());
}

string StringUtil::trimTrailing(string const & s) {
    auto rit = s.rbegin();
    while (rit.base() != s.begin() && isspace(*rit)) {
        rit++;
    }
    return string(s.begin(), rit.base());
}

string StringUtil::toLowerCase(string const & s) {
    string result = s;
    transform(s.begin(), s.end(), result.begin(), ::tolower);
    return result;
}

string StringUtil::toUpperCase(string const & s) {
    string result = s;
    transform(s.begin(), s.end(), result.begin(), ::toupper);
    return result;
}

}
}
