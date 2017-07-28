#pragma once

#include <algorithm>
#include <chrono>
#include <ctime>
#include <iostream>
#include <fstream>
#include <memory>
#include <sstream>
#include <vector>

#include "termcolor.hpp"

using std::ctime;
using std::cout;
using std::endl;
using std::find;
using std::make_shared;
using std::ofstream;
using std::ostream;
using std::ostringstream;
using std::shared_ptr;
using std::string;
using std::time_t;
using std::vector;

namespace mlogger {
    const int trace = 0;
    const int debug = 1;
    const int info = 2;
    const int warn = 3;
    const int error = 4;
    const int fatal = 5;

    const string LEVEL_STRINGS[] = {
        "[trace]",
        "[debug]",
        "[info] ",
        "[warn] ",
        "[error]",
        "[fatal]"
    };

}

class MLogger {

private:
    typedef ostream& (*ColourChanger)(ostream &);

    bool toCout_;
    bool toFile_;
    string filename_;
    vector<int> levels_;
    ofstream file_;

    static string getTime_() {
        time_t currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        string currentTimeStr = ctime(&currentTime);
        return currentTimeStr.erase(currentTimeStr.size() - 1); // Remove newline character
    }

    static string toString_(int level) {
        return mlogger::LEVEL_STRINGS[level];
    }

    static shared_ptr<MLogger> instance() {
        static shared_ptr<MLogger> instance_;
        if (!instance_) {
            instance_ = make_shared<MLogger>();
        }
        return instance_;
    }

public:
    static void toCout(bool toCout) {
        instance()->toCout_ = toCout;
    }

    static void toFile(bool toFile) {
        instance()->toFile_ = toFile;
    }

    static void filename(string filename) {
        instance()->filename_ = filename;
        instance()->toFile_ = true;
    }

    static void addLevel(int level) {
        instance()->levels_.push_back(level);
    }

    static void clearLevels() {
        instance()->levels_.resize(0);
    }

    static bool init() {
        if (instance()->toFile_) {
            instance()->file_.open(instance()->filename_);
            if (!instance()->file_.is_open()) {
                instance()->toFile_ = false;
                return false;
            }
        }
        return true;
    }

    static void log(int level, string message, ColourChanger colourChanger = termcolor::reset) {
        if (find(instance()->levels_.begin(), instance()->levels_.end(), level) == instance()->levels_.end()) {
            return;
        }
        ostringstream output;
        output << getTime_() << " " << toString_(level) << " : " << message;
        if (instance()->toCout_) {
            cout << colourChanger << output.str() << termcolor::reset << endl;
        }
        if (instance()->toFile_) {
            instance()->file_ << output.str() << endl;
        }
    }

    static void logTrace(string message) {
        log(mlogger::trace, message, termcolor::reset);
    }

    static void logDebug(string message) {
        log(mlogger::debug, message, termcolor::reset);
    }

    static void logInfo(string message) {
        log(mlogger::info, message, termcolor::green);
    }

    static void logWarn(string message) {
        log(mlogger::warn, message, termcolor::yellow);
    }

    static void logError(string message) {
        log(mlogger::error, message, termcolor::magenta);
    }

    static void logFatal(string message) {
        log(mlogger::fatal, message, termcolor::red);
    }

};
