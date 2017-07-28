#include "File.hpp"

namespace pyconv {
namespace file {

using std::ifstream;
using std::string;
using std::vector;

File::File() {}

bool File::open(string filename) {
    ifstream file;
    file.open(filename);
    if (!file.is_open()) {
        MLogger::logError("Unable to open file: " + filename);
        return false;
    }
    filelines_.resize(0);
    string line;
    while (getline(file, line)) {
        filelines_.push_back(line);
    }
    return true;
}

}
}