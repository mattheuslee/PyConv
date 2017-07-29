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
using pyconv::util::language::IsLanguageType;
using pyconv::util::language::LanguageType;
using pyconv::util::language::ToLanguageType;

class MainApp {

public:
    MainApp(vector<string> const & filesToConvert);

    void run();

private:
    LanguageType languageType_;
    vector<string> filesToConvert_;

    IsLanguageType isLanguageType_;
    ToLanguageType toLanguageType_;

    InputFile inputFile_;

    void openAndConvert_(string filename);

    void checkArgsValid_(vector<string> const & args);
    void extractArgs_(vector<string> args);

protected:


};

}
