#include "test/catch.hpp"

#include "main/language/LanguageType.hpp"
#include "main/language/types/line/LineUtil.hpp"

TEST_CASE("LineUtil class") {
    using pyconv::language::LanguageType;
    using pyconv::language::types::line::LineType;
    using pyconv::language::types::line::LineUtil;

    LineUtil<LanguageType::PYTHON> pythonLineUtil;

    SECTION("Line Type") {
        CHECK(LineUtil<LanguageType::PYTHON>::lineType("") == LineType::BLANK);
        CHECK(LineUtil<LanguageType::PYTHON>::lineType("elif i == 1:") == LineType::ELIF_STATEMENT);
        CHECK(LineUtil<LanguageType::PYTHON>::lineType("else:") == LineType::ELSE_STATEMENT);
        CHECK(LineUtil<LanguageType::PYTHON>::lineType("for i in list:") == LineType::FOR_LOOP);
        CHECK(LineUtil<LanguageType::PYTHON>::lineType("if i == 1:") == LineType::IF_STATEMENT);
        CHECK(LineUtil<LanguageType::PYTHON>::lineType("print i") == LineType::PRINT_STATEMENT);
        CHECK(LineUtil<LanguageType::PYTHON>::lineType("i = 3") == LineType::VARIABLE);
    }

    SECTION("Extract If Condition") {
        CHECK(LineUtil<LanguageType::PYTHON>::extractIfCondition("if i == 1:") == "i == 1");
    }

    SECTION("Extract Elif Condition") {
        CHECK(LineUtil<LanguageType::PYTHON>::extractElifCondition("elif i == 1:") == "i == 1");
    }
}
