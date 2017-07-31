#pragma once

#include <string>

namespace pyconv {
namespace language {
namespace types{
namespace line {

using std::string;

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
    static const line_t VARIABLE = 7;
    static const line_t VARIABLE_ASSIGNMENT = 8;
    static const line_t VARIABLE_DECLARATION = 9;
    static const line_t UNKNOWN = -1;

    static string lineTypeToString(line_t const & lineType) {
        switch(lineType) {
        case BLANK:
            return "blank";
        case ELIF_STATEMENT:
            return "elif";
        case ELSE_STATEMENT:
            return "else";
        case ELSE_IF_STATEMENT:
            return "else if";
        case FOR_LOOP:
            return "for";
        case IF_STATEMENT:
            return "if";
        case PRINT_STATEMENT:
            return "print";
        case VARIABLE:
            return "variable";
        case VARIABLE_ASSIGNMENT:
            return "variable assignment";
        case VARIABLE_DECLARATION:
            return "variable declaration";
        case UNKNOWN:
        default:
            return "unknown";
        }
    }

    static line_t firstWordToLineType(string const & firstWord) {
        if (firstWord == "") {
            return LineType::BLANK;
        } else if (firstWord == "elif") {
            return LineType::ELIF_STATEMENT;
        } else if (firstWord == "else") {
            return LineType::ELSE_STATEMENT;
        } else if (firstWord == "for") {
            return LineType::FOR_LOOP;
        } else if (firstWord == "if") {
            return LineType::IF_STATEMENT;
        } else if (firstWord == "print") {
            return LineType::PRINT_STATEMENT;
        }
        return LineType::VARIABLE;
    }

private:

protected:

};

}
}
}
}
