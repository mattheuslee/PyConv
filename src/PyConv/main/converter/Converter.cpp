#include "Converter.hpp"

namespace pyconv {
namespace converter {

Converter::Converter(int languageType) {
    languageType_ = languageType;
}

bool Converter::convert(vector<string> filelines) {
    vector<Line> originalLines;
    for (string line : filelines) {
        PythonLine pythonLine;
        pythonLine.line(line);
        //pythonLine = LineType::getLineType<LanguageType::PYTHON>(pythonLine);
        //originalLines.push_back(pythonLine);
    }

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
