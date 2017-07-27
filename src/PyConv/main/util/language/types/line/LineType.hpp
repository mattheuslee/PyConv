#pragma once

#include <string>

namespace pyconv {
namespace util {
namespace language {
namespace types {
namespace line {

enum Type {
    BLANK,
    VARIABLE_DECLARATION,
    VARIABLE_ASSIGNMENT,
    PRINT_STATEMENT,
    IF_STATEMENT,
    ELSE_STATEMENT,
    ELSE_IF_STATEMENT,
    ELIF_STATEMENT,
    FOR_LOOP,
    WHILE_LOOP,
    DO_WHILE_LOOP,
    UNKNOWN
};

class LineType {

public:
    Type type() const;
    std::string str() const;

private:

protected:
    std::string name_;
    Type type_;

};

}
}
}
}
}
