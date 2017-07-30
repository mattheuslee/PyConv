#define CATCH_CONFIG_RUNNER
#include "test/catch.hpp"

#include <string>
#include <vector>

#include "main/util/logging/MLogger.hpp"

int main(int argc, char* argv[]) {

    MLogger::toCout(true);
    MLogger::filename("./logs/PyConvTest.log");
    MLogger::addLevel(mlogger::info);
    MLogger::addLevel(mlogger::warn);
    MLogger::addLevel(mlogger::error);
    MLogger::addLevel(mlogger::fatal);
    MLogger::init();

    MLogger::logInfo("Starting tests");

    int result = Catch::Session().run(argc, argv);

    MLogger::logInfo("Tests complete");

    return result < 0xff ? result : 0xff;
}
