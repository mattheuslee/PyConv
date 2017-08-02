#include "test/catch.hpp"

#include <vector>

#include "main/language/LanguageType.hpp"
#include "main/language/types/line/LineUtil.hpp"

TEST_CASE("LineUtil class") {
    using std::vector;
    using pyconv::language::LanguageType;
    using pyconv::language::types::line::Line;
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

    SECTION("Extract For Statement") {
        CHECK(LineUtil<LanguageType::PYTHON>::extractForStatement("for i in {0, 10}:") == "i in {0, 10}");
    }

    SECTION("To String Vector") {
        auto lines = vector<Line>{};
        Line temp;
        lines.push_back(temp.line("test1"));
        lines.push_back(temp.line("test2"));
        auto stringVector = LineUtil<LanguageType::PYTHON>::toStringVector(lines);
        REQUIRE(stringVector.size() == 2);
        CHECK(stringVector[0] == "test1");
        CHECK(stringVector[1] == "test2");
    }
}
