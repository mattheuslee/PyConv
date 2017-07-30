CC = g++
COV_CFLAGS = -Wall -std=gnu++11 -I./src/PyConv -O0 -fno-inline -fno-inline-small-functions -fno-default-inline --coverage
NON_COV_CFLAGS = -Wall -std=gnu++11 -I./src/PyConv
OBJ = PyConv.o
GCOV_FILES_LOCATION = gcov_folder

MAIN_FILES := $(shell find ./src/PyConv/main -name "*.cpp")

# Source files for tests
TEST_FILES := $(shell find ./src/PyConv -not -name "PyConv.cpp" -and -name "*.cpp")
# Header files used for tests, for coverage
TEST_HEADERS := $(shell find ./src/PyConv/main -name "*.hpp")

PyConv: $(MAIN_FILES)
	make clean
	$(CC) -o PyConv $^ $(NON_COV_CFLAGS)

run: $(MAIN_FILES)
	make clean
	make PyConv
	./PyConv cpp ./convert/1.py

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
	make clean_retain_coverage

temp2:
	-mkdir $(GCOV_FILES_LOCATION)
#gather all .hpp files to be analysed
	find ./src/PyConv/main -name "*.hpp" -exec cp -t ./$(GCOV_FILES_LOCATION) {} \;
	cp *.gcno $(GCOV_FILES_LOCATION)
	cp *.gcda $(GCOV_FILES_LOCATION)
#put all .hpp filenames into filenames.txt
	find ./$(GCOV_FILES_LOCATION) -name "*.hpp" -and -not -name "catch.hpp" -exec basename {} > ./$(GCOV_FILES_LOCATION)/filenames.txt \;
	make clean_retain_coverage

temp:
	cp ./$(GCOV_FILES_LOCATION)/*.* .
	sh ./gcov_loop.sh
	make clean_retain_coverage
