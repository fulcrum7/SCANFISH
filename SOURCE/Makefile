all: headers
	g++ -o sf main.c canio.o cannet.o msg.o controller.o
headers: canio.h cannet.h msg.h controller.h
	g++ -c canio.cpp cannet.cpp msg.cpp controller.cpp
clean:
	rm -f *.o
