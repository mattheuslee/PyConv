#pragma once

#include <algorithm>
#include <string>

namespace pyconv {
namespace util {

using std::string;
using std::transform;

class StringUtil {

public:
    static string trim(string const & s);
    static string trimLeading(string const & s);
    static string trimTrailing(string const & s);

    static string toLowerCase(string const & s);
    static string toUpperCase(string const & s);

private:

protected:

};

}
}
