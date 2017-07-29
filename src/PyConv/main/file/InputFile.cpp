#include "InputFile.hpp"

namespace pyconv {
namespace file {

InputFile::InputFile() {}

void InputFile::open(string filename) {
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
    MLogger::logInfo("Successfully read input from: " + filename);
}

vector<string> InputFile::filelines() {
    return filelines_;
}

}
}
