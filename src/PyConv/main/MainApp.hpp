#pragma once

#include <string>
#include <utility>
#include <vector>

#include "main/converter/Converter.hpp"
#include "main/exception/ConversionException.hpp"
#include "main/exception/FileOpenException.hpp"
#include "main/exception/InvalidArgumentException.hpp"
#include "main/file/InputFile.hpp"
#include "main/file/OutputFile.hpp"
#include "main/language/LanguageType.hpp"
#include "main/language/types/line/Line.hpp"
#include "main/language/types/line/LineUtil.hpp"
#include "main/util/logging/MLogger.hpp"

namespace pyconv {

using std::make_pair;
using std::pair;
using std::string;
using std::vector;
using pyconv::converter::Converter;
using pyconv::exception::ConversionException;
using pyconv::exception::FileOpenException;
using pyconv::exception::InvalidArgumentException;
using pyconv::file::InputFile;
using pyconv::file::OutputFile;
using pyconv::language::LanguageType;
using pyconv::language::types::line::Line;
using pyconv::language::types::line::LineUtil;

class MainApp {

public:
    explicit MainApp(vector<string> const & args) {
        checkArgsValid_(args);
        extractArgs_(args);
    }

    void run() {
        for (auto const & inputOutputFiles : filesToConvert_) {
            openAndConvert_(inputOutputFiles);
        }
    }

private:
    int languageType_;
    vector<pair<string, string>> filesToConvert_;

    InputFile inputFile_;
    OutputFile outputFile_;

    void openAndConvert_(pair<string, string> const & inputOutputFiles) {
        try {
            inputFile_.open(inputOutputFiles.first);
        } catch (FileOpenException const & e) {
            MLogger::logWarn("Unable to open " + inputOutputFiles.first + ", skipping conversion");
            return;
        }
        try {
            auto convertedLines = convertToSpecifiedType_(inputFile_.filelines());
            outputFile_.filelines(LineUtil<LanguageType::PYTHON>::toStringVector(convertedLines));
            outputFile_.save(inputOutputFiles.second);
        } catch (ConversionException const & e) {
            MLogger::logError("Conversion error with " + inputOutputFiles.first + " : " + e.message());
        } catch (FileOpenException const & e) {
            MLogger::logError("Unable to open " + inputOutputFiles.second + " for saving");
        }
        MLogger::logInfo("Converted " + inputOutputFiles.first
                        + " successfully to " + LanguageType::languageTypeToString(languageType_)
                        + " and saved to " + inputOutputFiles.second);
    }

    vector<Line> convertToSpecifiedType_(vector<string> const & filelines) {
        if (languageType_ == LanguageType::PYTHON) {
            return Converter<LanguageType::PYTHON>::convert(filelines);
        } else {
            return Converter<LanguageType::CPP>::convert(filelines);
        }
    }

    void checkArgsValid_(vector<string> const & args) const {
        if (args.size() == 0) {
            MLogger::logFatal("No arguments provided");
            throw InvalidArgumentException("No arguments provided");
        } else if (args.size() % 2 == 0) {
            MLogger::logFatal("Pairs of input/output files required");
            throw InvalidArgumentException("Pairs of input/output files required");
        } else if (!LanguageType::isValidLanguageType(args[0])) {
            MLogger::logFatal("Invalid language type: " + args[0]);
            throw InvalidArgumentException("Invalid language type: " + args[0]);
        }
    }

    void extractArgs_(vector<string> args) {
        languageType_ = LanguageType::stringToLanguageType(args[0]);
        MLogger::logInfo("Language type selected: " + args[0]);
        args.erase(args.begin());
        for (auto i = 0; i < args.size(); i += 2) {
            filesToConvert_.push_back(make_pair(args[i], args[i + 1]));
        }
    }

protected:

};

}
