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
    explicit FileOpenException(string message) {
        message_ = message;
    }

    string message() const {
        return message_;
    }

    const char* what() {
        return message_.c_str();
    }

};

}
}
