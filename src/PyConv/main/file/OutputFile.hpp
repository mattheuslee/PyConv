#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "main/exception/FileOpenException.hpp"
#include "main/util/StringUtil.hpp"
#include "main/util/logging/MLogger.hpp"

namespace pyconv {
namespace file {

using std::ofstream;
using std::string;
using std::vector;
using pyconv::exception::FileOpenException;
using pyconv::util::StringUtil;

class OutputFile {

public:
    OutputFile() {}

    void filelines(vector<string> filelines) {
        filelines_ = filelines;
    }

    void save(string filename) {
        ofstream file;
        file.open(filename);
        if (!file.is_open()) {
            MLogger::logError("Unable to open file for output: " + filename);
            throw FileOpenException("Unable to open file for output: " + filename);
        }
        for (string line : filelines_) {
            file << StringUtil::trimTrailing(line) << endl;
        }
        MLogger::logInfo("Successfully saved output to: " + filename);
    }

private:
    string filename_;
    vector<string> filelines_;

protected:

};

}
}
