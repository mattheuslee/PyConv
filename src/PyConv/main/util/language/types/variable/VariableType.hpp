#pragma once

#include <string>

namespace pyconv {
namespace util {
namespace language {
namespace types {
namespace variable {

enum Type {
    INT,
    DOUBLE,
    STRING,
    UNKNOWN
};

class VariableType {

public:
    Type type() const;
    std::string str() const;

private:

protected:
    Type type_;
    std::string name_;

};

}
}
}
}
}
