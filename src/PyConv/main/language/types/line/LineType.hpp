#pragma once

namespace pyconv {
namespace language {
namespace types{
namespace line {

class LineType {

public:
    typedef int line_t;

    static const line_t BLANK = 0;
    static const line_t ELIF_STATEMENT = 1;
    static const line_t ELSE_IF_STATEMENT = 2;
    static const line_t ELSE_STATEMENT = 3;
    static const line_t FOR_LOOP = 4;
    static const line_t IF_STATEMENT = 5;
    static const line_t PRINT_STATEMENT = 6;
    static const line_t VARIABLE_ASSIGNMENT = 7;
    static const line_t VARIABLE_DECLARATION = 8;
    static const line_t UNKNOWN = -1;

private:

protected:

};

}
}
}
}
