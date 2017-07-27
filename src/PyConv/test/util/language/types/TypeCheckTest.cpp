#include "test/catch.hpp"

#include "main/util/language/types/TypeCheck.hpp"
#include "main/util/language/types/line/BlankLineType.hpp"
#include "main/util/language/types/line/VariableAssignmentLineType.hpp"
#include "main/util/language/types/line/VariableDeclarationLineType.hpp"
#include "main/util/language/types/variable/DoubleVariableType.hpp"
#include "main/util/language/types/variable/IntVariableType.hpp"
#include "main/util/language/types/variable/StringVariableType.hpp"
#include "main/util/language/types/variable/UnknownVariableType.hpp"

namespace pyconv {
namespace util {
namespace language {
namespace types {

TEST_CASE("Type Check class") {
    line::BlankLineType blankLineType;
    line::VariableAssignmentLineType variableAssignmentLineType;
    line::VariableDeclarationLineType variableDeclarationLineType;

    variable::DoubleVariableType doubleVariableType;
    variable::IntVariableType intVariableType;
    variable::StringVariableType stringVariableType;
    variable::UnknownVariableType unknownVariableType;

    SECTION("Is Blank Line Type") {
        CHECK(TypeCheck::isBlankLineType(blankLineType));
        CHECK_FALSE(TypeCheck::isBlankLineType(variableAssignmentLineType));
        CHECK_FALSE(TypeCheck::isBlankLineType(variableDeclarationLineType));
    }

    SECTION("Is Variable Assignment Line Type") {
        CHECK(TypeCheck::isVariableAssignmentLineType(variableAssignmentLineType));
        CHECK_FALSE(TypeCheck::isVariableAssignmentLineType(blankLineType));
        CHECK_FALSE(TypeCheck::isVariableAssignmentLineType(variableDeclarationLineType));
    }

    SECTION("Is Variable Declaration Line Type") {
        CHECK(TypeCheck::isVariableDeclarationLineType(variableDeclarationLineType));
        CHECK_FALSE(TypeCheck::isVariableDeclarationLineType(blankLineType));
        CHECK_FALSE(TypeCheck::isVariableDeclarationLineType(variableAssignmentLineType));
    }

    SECTION("Is Double Variable Type") {
        CHECK(TypeCheck::isDoubleVariableType(doubleVariableType));
        CHECK_FALSE(TypeCheck::isDoubleVariableType(intVariableType));
        CHECK_FALSE(TypeCheck::isDoubleVariableType(stringVariableType));
        CHECK_FALSE(TypeCheck::isDoubleVariableType(unknownVariableType));
    }

    SECTION("Is Int Variable Type") {
        CHECK(TypeCheck::isIntVariableType(intVariableType));
        CHECK_FALSE(TypeCheck::isIntVariableType(doubleVariableType));
        CHECK_FALSE(TypeCheck::isIntVariableType(stringVariableType));
        CHECK_FALSE(TypeCheck::isIntVariableType(unknownVariableType));
    }

    SECTION("Is String Variable Type") {
        CHECK(TypeCheck::isStringVariableType(stringVariableType));
        CHECK_FALSE(TypeCheck::isStringVariableType(doubleVariableType));
        CHECK_FALSE(TypeCheck::isStringVariableType(intVariableType));
        CHECK_FALSE(TypeCheck::isStringVariableType(unknownVariableType));
    }

    SECTION("Is Unknown Variable Type") {
        CHECK(TypeCheck::isUnknownVariableType(unknownVariableType));
        CHECK_FALSE(TypeCheck::isUnknownVariableType(doubleVariableType));
        CHECK_FALSE(TypeCheck::isUnknownVariableType(intVariableType));
        CHECK_FALSE(TypeCheck::isUnknownVariableType(stringVariableType));
    }
}

}
}
}
}
