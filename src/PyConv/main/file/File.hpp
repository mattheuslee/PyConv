#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "main/util/logging/MLogger.hpp"

namespace pyconv {
namespace file {

using std::string;
using std::vector;

class File {

public:
    File();
    bool open(string filename);

private:
    string filename_;
    vector<string> filelines_;

protected:

};

}
}