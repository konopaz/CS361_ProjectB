CPP = g++
CPPFLAGS = -g -Wall

ProjectB: ProjectB.o
	$(CPP) $(CPPFLAGS) ProjectB.o -o ProjectB

ProjectB.o: ProjectB.cpp
	$(CPP) $(CPPFLAGS) -c ProjectB.cpp -o ProjectB.o

clean:
	rm -f *.o ProjectB
