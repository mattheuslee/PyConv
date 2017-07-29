#include "OutputFile.hpp"

namespace pyconv {
namespace file {

using std::ifstream;
using std::string;
using std::vector;

OutputFile::OutputFile() {}

void OutputFile::filelines(vector<string> filelines) {
    filelines_ = filelines;
}

void OutputFile::save(string filename) {
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

}
}
