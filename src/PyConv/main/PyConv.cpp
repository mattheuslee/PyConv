#include <string>
#include <vector>

#include "main/MainApp.hpp"
#include "main/util/logging/MLogger.hpp"

using std::string;
using std::vector;

void initLogger();
vector<string> getArgs(int argc, char* argv[]);
void logArgs(vector<string> args);

int main(int argc, char* argv[]) {
    initLogger();

    vector<string> args = getArgs(argc, argv);
    logArgs(args);

    pyconv::MainApp mainApp(args);
    mainApp.run();

    MLogger::logInfo("Exiting PyConv");

    return 0;
}

void initLogger() {
    MLogger::toCout(true);
    MLogger::filename("./logs/PyConv.log");
    MLogger::addLevel(mlogger::info);
    MLogger::addLevel(mlogger::warn);
    MLogger::addLevel(mlogger::error);
    MLogger::addLevel(mlogger::fatal);
    if(!MLogger::init()) {
        MLogger::logWarn("failed to open file for logging");
    }
}

vector<string> getArgs(int argc, char* argv[]) {
    vector<string> args;
    for (int i = 0; i < argc; ++i) {
        args.emplace_back(argv[i]);
    }
    args.erase(args.begin()); // The first argument is always the name of the actual file
    return args;
}

void logArgs(vector<string> args) {
    MLogger::logInfo("Received args:");
    for (string arg : args) {
        MLogger::logInfo(arg);
    }
}
