#pragma once

#include <algorithm>
#include <cctype>
#include <iterator>
#include <sstream>
#include <string>

namespace pyconv {
namespace util {

using std::distance;
using std::ostringstream;
using std::string;
using std::transform;

class StringUtil {

public:
    template<typename T>
    static string toString(T const & t) {
        ostringstream result;
        result << t;
        return result.str();
    }

    static string trimLeading(string const & s) {
        auto it = s.begin();
        while (it != s.end() && isspace(*it)) {
            ++it;
        }
        return string(it, s.rbegin().base());
    }

    static string trimTrailing(string const & s) {
        auto rit = s.rbegin();
        while (rit.base() != s.begin() && isspace(*rit)) {
            ++rit;
        }
        return string(s.begin(), rit.base());
    }

    static string trim(string const & s) {
        return trimTrailing(trimLeading(s));
    }

    static string trimTrailingChar(string const & s, char const & c) {
        if (s.size() == 0) {
            return s;
        }
        if (s.back() == c) {
            return s.substr(0, s.size() - 1);
        } else {
            return s;
        }
    }

    static string toLowerCase(string const & s) {
        auto result = s;
        transform(s.begin(), s.end(), result.begin(), ::tolower);
        return result;
    }

    static string toUpperCase(string const & s) {
        auto result = s;
        transform(s.begin(), s.end(), result.begin(), ::toupper);
        return result;
    }

    static int numLeadingWhitespace(string const & s) {
        auto it = s.begin();
        while (it != s.end() && isspace(*it)) {
            ++it;
        }
        return distance(s.begin(), it);
    }

    static string addLeadingWhitespace(string const & s, int const & numWhitespace) {
        return string(numWhitespace, ' ') + s;
    }

    static string extractFirstWord(string const & s) {
        auto temp = trimLeading(s);
        auto it = s.begin();
        while (it != s.end() && !isspace(*it)) {
            ++it;
        }
        return string(s.begin(), it);
    }

    static bool isAllDigit(string const & s) {
        for (auto c : s) {
            if (!isdigit(c)) {
                return false;
            }
        }
        return true;
    }

private:

protected:

};

}
}
