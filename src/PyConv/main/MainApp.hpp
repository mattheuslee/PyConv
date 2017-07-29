#pragma once

#include <string>
#include <vector>

#include "main/converter/Converter.hpp"
#include "main/exception/FileOpenException.hpp"
#include "main/exception/InvalidArgumentException.hpp"
#include "main/file/InputFile.hpp"
#include "main/util/language/LanguageType.hpp"
#include "main/util/logging/MLogger.hpp"

namespace pyconv {

using std::string;
using std::vector;
using pyconv::converter::Converter;
using pyconv::exception::FileOpenException;
using pyconv::exception::InvalidArgumentException;
using pyconv::file::InputFile;
using pyconv::util::language::LanguageType;

class MainApp {

public:
    MainApp(vector<string> const & filesToConvert);

    void run();

private:
    int languageType_;
    vector<string> filesToConvert_;

    InputFile inputFile_;

    void openAndConvert_(string filename);

    void checkArgsValid_(vector<string> const & args);
    void extractArgs_(vector<string> args);

protected:


};

}
