#pragma once

namespace pyconv {
namespace util{
namespace language {
namespace types{
namespace line {

enum LineType {
    BLANK,
    ELIF_STATEMENT,
    ELSE_IF_STATEMENT,
    ELSE_STATEMENT,
    FOR_LOOP,
    IF_STATEMENT,
    PRINT_STATEMENT,
    UNKNOWN,
    VARIABLE_ASSIGNMENT,
    VARIABLE_DECLARATION,
};

}
}
}
}
}
