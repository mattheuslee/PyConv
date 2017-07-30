CC = g++
CFLAGS = -Wall -fprofile-arcs -ftest-coverage -std=gnu++11 -I./src/PyConv -O0 -fno-inline -fno-inline-small-functions -fno-default-inline
NON_COV_CFLAGS = -Wall -std=gnu++11 -I./src/PyConv
OBJ = PyConv.o
GCOV_FILES_LOCATION = gcov_folder

MAIN_FILES := $(shell find ./src/PyConv/main -name "*.cpp")

TEST_FILES := $(shell find ./src/PyConv -not -name "PyConv.cpp" -and -name "*.cpp")

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

test: $(TEST_FILES)
	make clean
	$(CC) -o test $^ $(CFLAGS)
	./test
	make clean

coverage: $(TEST_FILES)
	make clean
	$(CC) -o test $(TEST_FILES) $(CFLAGS)
	./test
	mkdir $(GCOV_FILES_LOCATION)
#gather all .hpp files to be analysed
	find ./src/PyConv/main -name "*.hpp" -exec cp -t ./$(GCOV_FILES_LOCATION) {} \;
	cp *.gcno $(GCOV_FILES_LOCATION)
	cp *.gcda $(GCOV_FILES_LOCATION)
	find ./$(GCOV_FILES_LOCATION) -name "*.hpp" -exec basename {} > ./$(GCOV_FILES_LOCATION)/filenames.txt \;

temp:
	cp ./$(GCOV_FILES_LOCATION)/*.* .
	sh ./gcov_loop.sh
	make clean_retain_coverage
