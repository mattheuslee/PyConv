#pragma once

#include <exception>
#include <string>

namespace pyconv {
namespace exception {

using std::exception;
using std::string;

class FileOpenException : public exception {
private:
    string message_;

public:
    FileOpenException(string message) {
        message_ = message;
    }

    string message() {
        return message_;
    }

    const char* what() {
        return message_.c_str();
    }

};

}
}