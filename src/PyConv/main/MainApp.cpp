#include "MainApp.hpp"

namespace pyconv {

MainApp::MainApp(vector<string> const & args) {
    checkArgsValid_(args);
    extractArgs_(args);
}

void MainApp::run() {
    for (string filename : filesToConvert_) {
        openAndConvert_(filename);
    }
}

void MainApp::openAndConvert_(string filename) {
    Converter converter(languageType_);
    try {
        inputFile_.open(filename);
    } catch (FileOpenException const & e) {
        MLogger::logWarn("Unable to open " + filename + ", skipping conversion");
        return;
    }
    if (converter.convert(inputFile_.filelines())) {
        MLogger::logInfo("Converted " + filename + " successfully");
    } else {
        MLogger::logWarn("Unable to convert " + filename);
    }
}

void MainApp::checkArgsValid_(vector<string> const & args) {
    if (args.size() == 0) {
        MLogger::logFatal("No arguments provided");
        throw InvalidArgumentException("No arguments provided");
    } else if (args.size() == 1) {
        MLogger::logFatal("Only one argument provided");
        throw InvalidArgumentException("Only one argument provided");
    } else if (!isLanguageType_(args[0])) {
        MLogger::logFatal("Invalid language type: " + args[0]);
        throw InvalidArgumentException("Invalid language type: " + args[0]);
    }
}

void MainApp::extractArgs_(vector<string> args) {
    languageType_ = toLanguageType_(args[0]);
    MLogger::logInfo("Language type selected: " + args[0]);
    args.erase(args.begin());
    filesToConvert_ = args;
}

}
