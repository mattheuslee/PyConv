#include "main/util/logging/MLogger.hpp"

#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    using std::string;
    using std::vector;

    MLogger::toCout(true);
    MLogger::filename("./logs/PyConv.log");
    MLogger::addLevel(mlogger::info);
    MLogger::addLevel(mlogger::warn);
    MLogger::addLevel(mlogger::error);
    if(!MLogger::init()) {
        MLogger::logWarn("failed to open file for logging");
    }

    vector<string> args;
    for (int i = 0; i < argc; ++i) {
        args.emplace_back(argv[i]);
    }

    MLogger::logInfo("Received args:");
    for (string arg : args) {
        MLogger::logInfo(arg);
    }

    return 0;
}
