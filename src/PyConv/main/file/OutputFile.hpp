#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "main/util/StringUtil.hpp"
#include "main/util/logging/MLogger.hpp"

namespace pyconv {
namespace file {

using std::ofstream;
using std::string;
using std::vector;
using pyconv::util::StringUtil;

class OutputFile {

public:
    OutputFile();
    void filelines(vector<string> filelines);
    bool save(string filename);

private:
    string filename_;
    vector<string> filelines_;

protected:

};

}
}
