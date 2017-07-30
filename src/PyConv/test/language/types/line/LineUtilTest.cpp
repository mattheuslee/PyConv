#include "test/catch.hpp"

#include "main/language/LanguageType.hpp"
#include "main/language/types/line/LineUtil.hpp"

TEST_CASE("LineUtil class") {
    using pyconv::language::LanguageType;
    using pyconv::language::types::line::LineType;
    using pyconv::language::types::line::LineUtil;

    LineUtil<LanguageType::PYTHON> pythonLineUtil;

    SECTION("Line Type") {
        CHECK(LineUtil<LanguageType::PYTHON>::lineType("elif") == LineType::ELIF_STATEMENT);
        CHECK(LineUtil<LanguageType::PYTHON>::lineType("else") == LineType::ELSE_STATEMENT);
        CHECK(LineUtil<LanguageType::PYTHON>::lineType("for") == LineType::FOR_LOOP);
        CHECK(LineUtil<LanguageType::PYTHON>::lineType("if") == LineType::IF_STATEMENT);
        CHECK(LineUtil<LanguageType::PYTHON>::lineType("print") == LineType::PRINT_STATEMENT);
        CHECK(LineUtil<LanguageType::PYTHON>::lineType("blah = 3") == LineType::VARIABLE);
    }
}
