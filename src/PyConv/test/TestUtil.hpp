#pragma once

#include <string>
#include <vector>

namespace pyconv {

using std::string;
using std::vector;

class TestUtil {

public:
    static const int SAMPLE_NUM_LINES = 11;

    static vector<string> getSamplePythonLineStrings() {
        vector<string> temp {
            "i = 5",
            "i = 10",
            "j = i",
            "for k in {0, 10}:",
            "    if k == 5:",
            "        print (\"5!\")",
            "    elif k == 10:",
            "        print (\"10!\")",
            "    else:",
            "        print (\"Not 5 or 10!\")",
            ""
        };
        return temp;
    }

private:

protected:

};

}
