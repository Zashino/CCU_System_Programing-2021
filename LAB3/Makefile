all:
	gcc error.c fsyncbuffersize4096.c -o fsyncbuffersize4096.o
	gcc error.c buffersize100.c -o buffersize100.o
	gcc error.c buffersize4096.c -o buffersize4096.o
	gcc error.c buffersize8192.c -o buffersize8192.o
	gcc error.c buffersize16384.c -o buffersize16384.o

clean:
	rm -f *.o
