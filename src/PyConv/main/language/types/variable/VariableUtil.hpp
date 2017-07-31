#pragma once

#include <string>

#include "main/language/LanguageType.hpp"
#include "main/language/types/variable/VariableType.hpp"
#include "main/util/StringUtil.hpp"

namespace pyconv {
namespace language {
namespace types {
namespace variable {

using std::string;
using pyconv::language::LanguageType;
using pyconv::language::types::variable::VariableType;
using pyconv::util::StringUtil;

using language_t = LanguageType::language_t;
using variable_t = VariableType::variable_t;

template<language_t L = LanguageType::PYTHON>
class VariableUtil {

public:
    static string extractVariableName(string const & line) {
        return StringUtil::extractFirstWord(line);
    }

    static string extractVariableAssignment(string const & line) {
        auto start = line.find_first_of('=');
        if (start == string::npos) {
            return "";
        }
        return StringUtil::trim(line.substr(start + 1));
    }

    static variable_t getVariableType(string const & assignment) {
        if (assignment.find_first_of('.') != string::npos) {
            return VariableType::DOUBLE;
        } else if (StringUtil::isAllDigit(assignment)) {
            return VariableType::INT;
        } else if (assignment.find_first_of("\"\'") != string::npos) {
            return VariableType::STRING;
        } else {
            return VariableType::UNKNOWN;
        }
    }

private:

protected:

};

}
}
}
}
