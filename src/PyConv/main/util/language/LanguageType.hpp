#pragma once

#include <string>

#include <main/util/StringUtil.hpp>

namespace pyconv {
namespace util {
namespace language {

using std::string;
using pyconv::util::StringUtil;

class LanguageType {

public:
    typedef int language_t;

    static const int PYTHON = 0;
    static const int CPP = 1;
    static const int UNKNOWN = -1;

    static bool isValidLanguageType(int const & language);

    static bool isValidLanguageType(string const & language);

    static int stringToLanguageType(string const & language);

    static string languageTypeToString(int const & language);

private:

protected:

};

}
}
}
