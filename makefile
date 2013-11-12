
main: webgraph.o main.o
	g++ -o p3 webgraph.o main.o 

webgraph.o: webgraph.cpp webgraph.h
	g++ -c webgraph.cpp

main.o: main.cpp
	g++ -c main.cpp
clean:	
	rm *.o p3
