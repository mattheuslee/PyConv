CC = g++
CFLAGS = -Wall -fprofile-arcs -ftest-coverage -std=c++11 -I./src/PyConv
DEPS =
OBJ = PyConv.o
FILES_UNDER_TEST_LOCATION = gcov_folder

MAIN_FILES := $(shell find ./src/PyConv/main -name "*.cpp" -o -name "*.cc")

TEST_FILES := $(shell find ./src/PyConv -not -name "PyConv.cpp" -and -name "*.cpp")

FILES_UNDER_TEST := $(shell find ./src/PyConv/main -not -name "PyConv.cpp" -and -name "*.cpp")

TEMP = ./src/PyConv/main/PyConv.cpp \
./src/PyConv/main/util/logging/easylogging++.cc

TEST = ./src/PyConv/test/MainTest.cpp \
./src/PyConv/test/util/language/python/ReservedWordsTest.cpp \
./src/PyConv/main/util/language/python/ReservedWords.cpp \
./src/PyConv/test/util/language/types/TypeCheckTest.cpp \
./src/PyConv/main/util/language/types/TypeCheck.cpp \
./src/PyConv/main/util/language/types/line/LineType.cpp \
./src/PyConv/test/util/language/types/line/BlankLineTypeTest.cpp \
./src/PyConv/main/util/language/types/line/BlankLineType.cpp \
./src/PyConv/test/util/language/types/line/VariableAssignmentLineTypeTest.cpp \
./src/PyConv/main/util/language/types/line/VariableAssignmentLineType.cpp \
./src/PyConv/test/util/language/types/line/VariableDeclarationLineTypeTest.cpp \
./src/PyConv/main/util/language/types/line/VariableDeclarationLineType.cpp \
./src/PyConv/main/util/language/types/variable/VariableType.cpp \
./src/PyConv/test/util/language/types/variable/IntVariableTypeTest.cpp \
./src/PyConv/main/util/language/types/variable/IntVariableType.cpp \
./src/PyConv/test/util/language/types/variable/DoubleVariableTypeTest.cpp \
./src/PyConv/main/util/language/types/variable/DoubleVariableType.cpp \
./src/PyConv/test/util/language/types/variable/StringVariableTypeTest.cpp \
./src/PyConv/main/util/language/types/variable/StringVariableType.cpp \
./src/PyConv/test/util/language/types/variable/UnknownVariableTypeTest.cpp \
./src/PyConv/main/util/language/types/variable/UnknownVariableType.cpp

PyConv: $(MAIN_FILES)
	$(CC) -o PyConv $^ $(CFLAGS)

run:
	make clean
	make PyConv
	./Pyconv

clean:
	rm -f ./*.gcda ./*.gcno ./*.o ./*.exe ./*.gcov gcovlog.txt

clean_retain_coverage:
	rm -f -r gcov_folder
	mkdir temp
	mv ./*.cpp.gcov temp
	make clean
	mv temp/* .
	rm -r temp

test: $(TEST_FILES)
	$(CC) -o test $^ $(CFLAGS)
	./test
	make clean

coverage: $(TEST_FILES) $(FILES_UNDER_TEST)
	$(CC) -o test $(TEST_FILES) $(CFLAGS)
	./test
	mkdir $(FILES_UNDER_TEST_LOCATION)
	find ./src/PyConv/main -not -name "PyConv.cpp" -and -name "*.cpp" -exec cp -t ./$(FILES_UNDER_TEST_LOCATION) {} \;
	cp *.gcno $(FILES_UNDER_TEST_LOCATION)
	cp *.gcda $(FILES_UNDER_TEST_LOCATION)
	cp gcov_loop.sh $(FILES_UNDER_TEST_LOCATION)
	cd $(FILES_UNDER_TEST_LOCATION)
	find -name "*.cpp" -exec basename {} > ./filenames.txt \;
	sh ./gcov_loop.sh
	cd $(FILES_UNDER_TEST_LOCATION)
	cp ./*.cpp.gcov ../
	cd ..
	make clean_retain_coverage
