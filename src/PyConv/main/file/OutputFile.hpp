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
    OutputFile();
    void filelines(vector<string> filelines);
    void save(string filename);

private:
    string filename_;
    vector<string> filelines_;

protected:

};

}
}
