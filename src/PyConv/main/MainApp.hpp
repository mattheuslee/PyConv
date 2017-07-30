#pragma once

#include <string>
#include <vector>

#include "main/converter/Converter.hpp"
#include "main/exception/ConversionException.hpp"
#include "main/exception/FileOpenException.hpp"
#include "main/exception/InvalidArgumentException.hpp"
#include "main/file/InputFile.hpp"
#include "main/language/LanguageType.hpp"
#include "main/language/types/line/LineBase.hpp"
#include "main/util/logging/MLogger.hpp"

namespace pyconv {

using std::string;
using std::vector;
using pyconv::converter::Converter;
using pyconv::exception::ConversionException;
using pyconv::exception::FileOpenException;
using pyconv::exception::InvalidArgumentException;
using pyconv::file::InputFile;
using pyconv::language::LanguageType;
using pyconv::language::types::line::LineBase;

class MainApp {

public:
    explicit MainApp(vector<string> const & args) {
        checkArgsValid_(args);
        extractArgs_(args);
    }

    void run() {
        for (string const & filename : filesToConvert_) {
            openAndConvert_(filename);
        }
    }

private:
    int languageType_;
    vector<string> filesToConvert_;

    InputFile inputFile_;

    void openAndConvert_(string const & filename) {
        try {
            inputFile_.open(filename);
        } catch (FileOpenException const & e) {
            MLogger::logWarn("Unable to open " + filename + ", skipping conversion");
            return;
        }
        try {
            vector<LineBase> convertedLines = convertForType_(inputFile_.filelines());
        } catch (ConversionException const & e) {
            MLogger::logError("Conversion error with " + filename + " : " + e.message());
        }
        MLogger::logInfo("Converted " + filename + " successfully to " + LanguageType::languageTypeToString(languageType_));
    }

    vector<LineBase> convertForType_(vector<string> const & filelines) {
        switch (languageType_) {
        case LanguageType::PYTHON:
            return Converter<LanguageType::PYTHON>::convert(filelines);
        case LanguageType::CPP:
            return Converter<LanguageType::CPP>::convert(filelines);
        case LanguageType::UNKNOWN:
        default:
            return Converter<LanguageType::UNKNOWN>::convert(filelines);
        }
    }

    void checkArgsValid_(vector<string> const & args) const {
        if (args.size() == 0) {
            MLogger::logFatal("No arguments provided");
            throw InvalidArgumentException("No arguments provided");
        } else if (args.size() == 1) {
            MLogger::logFatal("Only one argument provided");
            throw InvalidArgumentException("Only one argument provided");
        } else if (!LanguageType::isValidLanguageType(args[0])) {
            MLogger::logFatal("Invalid language type: " + args[0]);
            throw InvalidArgumentException("Invalid language type: " + args[0]);
        }
    }

    void extractArgs_(vector<string> args) {
        languageType_ = LanguageType::stringToLanguageType(args[0]);
        MLogger::logInfo("Language type selected: " + args[0]);
        args.erase(args.begin());
        filesToConvert_ = args;
    }

protected:

};

}
