CC = g++
CFLAGS = -Wall -fprofile-arcs -ftest-coverage
DEPS =
OBJ = PyConv.o

PyConv: ./src/PyConv/main/PyConv.cpp
	$(CC) -o PyConv $^ $(CFLAGS)

clean:
	rm -f ./*.gcda ./*.gcno ./*.o ./*.exe

test: ./src/PyConv/test/basic.cpp
	$(CC) -o test $^ $(CFLAGS)
	./test