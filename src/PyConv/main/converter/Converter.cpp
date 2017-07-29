#include "Converter.hpp"

namespace pyconv {
namespace converter {

Converter::Converter(int languageType) {
    languageType_ = languageType;
}

bool Converter::convert(vector<string> filelines) {
    switch (languageType_) {
    case LanguageType::PYTHON:
        return false;
    case LanguageType::CPP:
        return true;
    default:
        return false;
    }
}

}
}
