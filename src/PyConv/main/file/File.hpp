#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "main/util/StringUtil.hpp"
#include "main/util/logging/MLogger.hpp"

namespace pyconv {
namespace file {

using std::string;
using std::vector;
using pyconv::util::StringUtil;

class File {

public:
    File();
    bool open(string filename);
    vector<string> filelines();

private:
    string filename_;
    vector<string> filelines_;

protected:

};

}
}
