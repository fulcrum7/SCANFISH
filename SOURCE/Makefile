all: headers
	g++ -D_REENTRANT -o sf main.cpp canio.o cannet.o msg.o controller.o  -lpthread
headers: canio.h cannet.h msg.h controller.h canlistener.h sferror.h
	g++ -D_REENTRANT -c canio.cpp cannet.cpp msg.cpp controller.cpp -lpthread
clean:
	rm -f *.o
