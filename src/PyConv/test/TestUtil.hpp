#pragma once

#include <string>
#include <vector>

namespace pyconv {

using std::string;
using std::vector;

class TestUtil {

public:
    static vector<string> getSamplePythonLineStrings() {
        vector<string> temp {
            "i = 5",
            "i = 10",
            "if i == 5:",
            "    print \"5!\"",
            "else:",
            "    print \"not 5!\"",
            ""
        };
        return temp;
    }

private:

protected:

};

}
