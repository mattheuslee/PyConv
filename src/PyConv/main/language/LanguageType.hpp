#pragma once

#include <string>

#include <main/util/StringUtil.hpp>

namespace pyconv {
namespace language {

using std::string;
using pyconv::util::StringUtil;

class LanguageType {

public:
    typedef int language_t;

    static const language_t PYTHON = 0;
    static const language_t CPP = 1;
    static const language_t UNKNOWN = -1;

    static bool isValidLanguageType(language_t const & language) {
        return language == PYTHON || language == CPP;
    }

    static bool isValidLanguageType(string const & language) {
        return language == "python" || language == "cpp";
    }

    static language_t stringToLanguageType(string const & language) {
        if (StringUtil::toLowerCase(language) == "python") {
            return PYTHON;
        } else if (StringUtil::toLowerCase(language) == "cpp") {
            return CPP;
        } else {
            return UNKNOWN;
        }
    }

    static string languageTypeToString(language_t const & language) {
        switch (language) {
        case PYTHON:
            return "python";
        case CPP:
            return "cpp";
        default:
            return "unknown";
        }
    }

private:

protected:

};

}
}
