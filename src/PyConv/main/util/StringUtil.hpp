#pragma once

#include <string>

namespace pyconv {
namespace util {

using std::string;

class StringUtil {

public:
    static string trim(string const & s);
    static string trimLeading(string const & s);
    static string trimTrailing(string const & s);

private:

protected:

};

}
}
