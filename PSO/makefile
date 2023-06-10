PSO:main.o Gene.o Function.o Partical.o Range.o Swarm.o
	g++ -o PSO main.o Gene.o Function.o Partical.o Range.o Swarm.o
main.o:main.cpp
	g++ -o main.o -c main.cpp
Function.o:
	g++ -o Function.o -c Function.cpp
Partical.o: 
	g++ -o Partical.o -c Partical.cpp
Swarm.o:
	g++ -o Swarm.o -c Swarm.cpp
Gene.o:Gene.cpp
	g++ -o Gene.o -c Gene.cpp
Range.o:Range.cpp
	g++ -o Range.o -c Range.cpp
clean:
	rm PSO main.o Gene.o Function.o Partical.o Range.o Swarm.o
	