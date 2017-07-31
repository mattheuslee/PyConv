#pragma once

#include <string>
#include <vector>

namespace pyconv {

using std::string;
using std::vector;

class TestUtil {

public:
    static const int SAMPLE_NUM_LINES = 10;

    static vector<string> getSamplePythonLineStrings() {
        vector<string> temp {
            "i = 5",
            "i = 10",
            "j = i",
            "if i == 5:",
            "    print (\"5!\")",
            "elif i == 10:",
            "    print (\"10!\")",
            "else:",
            "    print (\"Not 5 or 10!\")",
            ""
        };
        return temp;
    }

private:

protected:

};

}
