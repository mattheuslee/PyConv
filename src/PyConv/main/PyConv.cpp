#include "util/logging/easylogging++.h"

INITIALIZE_EASYLOGGINGPP

int main(int argc, char* argv[]) {

    LOG(INFO) << "Testing logs";

    return 0;
}
