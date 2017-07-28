CC = g++
CFLAGS = -Wall -fprofile-arcs -ftest-coverage -std=c++11 -I./src/PyConv
DEPS =
OBJ = PyConv.o
GCOV_FILES_LOCATION = gcov_folder

MAIN_FILES := $(shell find ./src/PyConv/main -name "*.cpp")

TEST_FILES := $(shell find ./src/PyConv -not -name "PyConv.cpp" -and -name "*.cpp")

PyConv: $(MAIN_FILES)
	$(CC) -o PyConv $^ $(CFLAGS)

run: $(MAIN_FILES)
	make clean
	make PyConv
	./Pyconv

clean:
	rm -f -r ./*.cpp ./*.gcda ./*.gcno ./*.o ./*.exe ./*.gcov gcovlog.txt filenames.txt gcov_folder

clean_retain_coverage:
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
	mkdir $(GCOV_FILES_LOCATION)
	find ./src/PyConv/main -not -name "PyConv.cpp" -and -name "*.cpp" -exec cp -t ./$(GCOV_FILES_LOCATION) {} \;
	cp *.gcno $(GCOV_FILES_LOCATION)
	cp *.gcda $(GCOV_FILES_LOCATION)
	find ./$(GCOV_FILES_LOCATION) -name "*.cpp" -exec basename {} > ./$(GCOV_FILES_LOCATION)/filenames.txt \;
	cp ./$(GCOV_FILES_LOCATION)/*.* .
	sh ./gcov_loop.sh
	make clean_retain_coverage
