CC=g++
CFLAGS=-Wall

EXEC=matrix_operations.exe

all: $(EXEC)

$(EXEC): main.cpp matrix.cpp matrix.hpp
	$(CC) $(CFLAGS) -o $(EXEC) main.cpp matrix.cpp

clean:
	rm -f matrix_operations.exe