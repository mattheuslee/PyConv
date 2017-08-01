#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "main/exception/FileOpenException.hpp"
#include "main/util/StringUtil.hpp"
#include "main/util/logging/MLogger.hpp"

namespace pyconv {
namespace file {

using std::ifstream;
using std::string;
using std::vector;
using pyconv::exception::FileOpenException;
using pyconv::util::StringUtil;

class InputFile {

public:
    InputFile() {}

    void open(string filename) {
        ifstream file;
        file.open(filename);
        if (!file.is_open()) {
            MLogger::logError("Unable to open file for input: " + filename);
            throw FileOpenException("Unable to open file for input: " + filename);
        }
        filelines_.resize(0);
        string line;
        while (getline(file, line)) {
            filelines_.push_back(StringUtil::trimTrailing(line));
        }
        filelines_.push_back("");
        MLogger::logInfo("Successfully read input from: " + filename);
    }
    vector<string> filelines() const {
        return filelines_;
    }

private:
    string filename_;
    vector<string> filelines_;

protected:

};

}
}
