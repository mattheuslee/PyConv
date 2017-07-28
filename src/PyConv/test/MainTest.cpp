#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

#include "main/util/logging/MLogger.hpp"

int main(int argc, char* argv[]) {

    MLogger::toCout(true);
    MLogger::filename("./logs/PyConvTest.log");
    MLogger::addLevel(mlogger::info);
    MLogger::addLevel(mlogger::warn);
    MLogger::addLevel(mlogger::error);
    MLogger::init();

    MLogger::logInfo("Starting tests");

    int result = Catch::Session().run(argc, argv);

    return result < 0xff ? result : 0xff;
}
