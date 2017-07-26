CC = g++
CFLAGS = -Wall -fprofile-arcs -ftest-coverage -std=c++11
DEPS =
OBJ = PyConv.o

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

test: ./src/PyConv/test/MainTest.cpp ./src/PyConv/test/util/language/python/ReservedWordsTest.cpp ./src/PyConv/main/util/language/python/ReservedWords.cpp
	$(CC) -o test $^ $(CFLAGS)
	./test
	gcov ReservedWords.cpp > gcovlog.txt
	make partially_clean

coverage:
	make test