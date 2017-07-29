#include "Converter.hpp"

namespace pyconv {
namespace converter {

Converter::Converter(language_t languageType) {
    languageType_ = languageType;
}

bool Converter::convert(vector<string> filelines) {
    vector<PythonLine> originalLines = Parser<LanguageType::PYTHON>::process(filelines);

    switch (languageType_) {
    case LanguageType::PYTHON:
        MLogger::logWarn("Converting from python to python, nothing to be done");
        return false;
    case LanguageType::CPP:

        return true;
    default:
        return false;
    }
}

}
}
