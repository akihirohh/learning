CC = g++ -std=c++11
CFLAGS = -Wno-deprecated-declarations -fpermissive  

make: matrix.cpp
	$(CC) $(CFLAGS) -o matrix matrix.cpp
