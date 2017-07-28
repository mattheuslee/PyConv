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

bool OutputFile::save(string filename) {
    ofstream file;
    file.open(filename);
    if (!file.is_open()) {
        MLogger::logError("Unable to open file for output: " + filename);
        return false;
    }
    for (string line : filelines_) {
        file << StringUtil::trimTrailing(line) << endl;
    }
    MLogger::logInfo("Successfully saved output to: " + filename);
    return true;
}

}
}
