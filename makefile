CC = g++
COV_CFLAGS = -Wall -fprofile-arcs -ftest-coverage -std=gnu++11 -I./src/PyConv -O0 -fno-inline -fno-inline-small-functions -fno-default-inline
NON_COV_CFLAGS = -Wall -std=gnu++11 -I./src/PyConv
GCOV_FILES_LOCATION = gcov_folder

MAIN_FILES := $(shell find ./src/PyConv/main -name "*.cpp")

# Source files for tests
TEST_FILES := $(shell find ./src/PyConv -not -name "PyConv.cpp" -and -not -path "./src/PyConv/test/testfiles/*" -and -name "*.cpp")
# Header files used for tests, for coverage
TEST_HEADERS := $(shell find ./src/PyConv/main -name "*.hpp")

suite:
	make PyConv
	make test

PyConv: $(MAIN_FILES)
	make clean
	$(CC) -o PyConv $^ $(NON_COV_CFLAGS)

run: $(MAIN_FILES)
	make clean
	make PyConv
	./PyConv cpp ./input/1.py ./output/1.cpp

clean:
	rm -f -r ./*.cpp ./*.gcda ./*.gcno ./*.o ./*.exe ./*.gcov gcovlog.txt filenames.txt gcov_folder

clean_gcov_files:
	rm -f -r ./*.cpp ./*.gcda ./*.gcno ./*.gcov gcovlog.txt filenames.txt gcov_folder

clean_retain_coverage:
	-mkdir temp
	-cp ./*.gcda temp
	make clean
	-cp ./temp/*.* .
	-rm -f -r temp
	rm MainAppTest.gcda TestMain.gcda

test: $(TEST_FILES)
	make clean
	$(CC) -o test $^ $(COV_CFLAGS)
	./test
	make clean

coverage: $(TEST_FILES)
	make clean
	$(CC) -o test $^ $(COV_CFLAGS)
	./test
