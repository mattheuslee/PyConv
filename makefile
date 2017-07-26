CC = g++
CFLAGS = -Wall -fprofile-arcs -ftest-coverage -std=c++11 -I./src/PyConv
DEPS =
OBJ = PyConv.o
TEST_FILES = ./src/PyConv/test/MainTest.cpp \
./src/PyConv/test/util/language/python/ReservedWordsTest.cpp \
./src/PyConv/main/util/language/python/ReservedWords.cpp \
./src/PyConv/main/util/language/types/variable/VariableType.cpp \
./src/PyConv/test/util/language/types/variable/IntVariableTypeTest.cpp \
./src/PyConv/main/util/language/types/variable/IntVariableType.cpp \
./src/PyConv/test/util/language/types/variable/DoubleVariableTypeTest.cpp \
./src/PyConv/main/util/language/types/variable/DoubleVariableType.cpp \
./src/PyConv/test/util/language/types/variable/StringVariableTypeTest.cpp \
./src/PyConv/main/util/language/types/variable/StringVariableType.cpp \
./src/PyConv/test/util/language/types/variable/UnknownVariableTypeTest.cpp \
./src/PyConv/main/util/language/types/variable/UnknownVariableType.cpp

PyConv: ./src/PyConv/main/PyConv.cpp
	$(CC) -o PyConv $^ $(CFLAGS)

clean:
	rm -f ./*.gcda ./*.gcno ./*.o ./*.exe ./*.gcov gcovlog.txt

partially_clean:
	mkdir temp
	mv ./*.cpp.gcov temp
	make clean
	mv temp/* .
	rm -r temp

test: $(TEST_FILES)
	$(CC) -o test $^ $(CFLAGS)
	./test
	make clean

coverage: $(TEST_FILES)
	$(CC) -o test $^ $(CFLAGS)
	./test
	gcov ReservedWords.cpp > gcovlog.txt
	gcov IntVariableType.cpp > gcovlog.txt
	gcov DoubleVariableType.cpp > gcovlog.txt
	make partially_clean
