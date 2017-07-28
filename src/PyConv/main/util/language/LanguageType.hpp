#pragma once

#include <string>

namespace pyconv {
namespace util {
namespace language {

using std::string;

enum LanguageType {
    PYTHON,
    CPP,
    UNKNOWN
};

struct IsLanguageType {
    bool operator()(string language) {
        return language == "python" || language == "cpp";
    }
};

struct ToLanguageType {
    LanguageType operator()(string language) {
        if (language == "python") {
            return LanguageType::PYTHON;
        } else if (language == "cpp") {
            return LanguageType::CPP;
        }
        return LanguageType::UNKNOWN;
    }
};

}
}
}
