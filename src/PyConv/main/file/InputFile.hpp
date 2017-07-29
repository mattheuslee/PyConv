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
    InputFile();
    void open(string filename);
    vector<string> filelines();

private:
    string filename_;
    vector<string> filelines_;

protected:

};

}
}
