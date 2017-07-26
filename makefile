CC = g++
CFLAGS = -Wall -fprofile-arcs -ftest-coverage
DEPS =
OBJ = PyConv.o

PyConv: ./src/PyConv/main/PyConv.cpp
	$(CC) -o PyConv $^ $(CFLAGS)

clean:
	rm -f ./*.gcda ./*.gcno ./*.o ./*.exe ./*.gcov

test: ./src/PyConv/test/basic.cpp ./src/PyConv/main/source.cpp
	$(CC) -o test $^ $(CFLAGS)
	./test
	gcov source.cpp > gcovlog.txt
	mkdir temp
	mv ./source.cpp.gcov temp
	make clean
	mv temp/* .
	rm -r temp
