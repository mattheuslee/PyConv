#include "util/logging/easylogging++.h"

#include <string>
#include <vector>

INITIALIZE_EASYLOGGINGPP

int main(int argc, char* argv[]) {
    using std::string;
    using std::vector;

    vector<string> args;
    for (int i = 0; i < argc; ++i) {
        args.emplace_back(argv[i]);
    }

    for (string arg : args) {
        LOG(INFO) << arg;
    }

    LOG(INFO) << "Testing logs";

    return 0;
}
