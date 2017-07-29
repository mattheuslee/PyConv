#include "LanguageType.hpp"

namespace pyconv {
namespace language {

using language_t = LanguageType::language_t;

const language_t LanguageType::PYTHON;
const language_t LanguageType::CPP;
const language_t LanguageType::UNKNOWN;

bool LanguageType::isValidLanguageType(language_t const & language) {
    return language == PYTHON || language == CPP;
}

bool LanguageType::isValidLanguageType(string const & language) {
    return language == "python" || language == "cpp";
}

language_t LanguageType::stringToLanguageType(string const & language) {
    if (StringUtil::toLowerCase(language) == "python") {
        return PYTHON;
    } else if (StringUtil::toLowerCase(language) == "cpp") {
        return CPP;
    } else {
        return UNKNOWN;
    }
}

string LanguageType::languageTypeToString(int const & language) {
    switch (language) {
    case PYTHON:
        return "python";
    case CPP:
        return "cpp";
    default:
        return "unknown";
    }
}

}
}
