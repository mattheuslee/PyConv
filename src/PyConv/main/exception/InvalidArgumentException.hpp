#pragma once

#include <exception>
#include <string>

namespace pyconv {
namespace exception {

using std::exception;
using std::string;

class InvalidArgumentException : public exception {
private:
    string message_;

public:
    explicit InvalidArgumentException(string message) {
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
