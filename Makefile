CPP = g++
CPPFLAGS = -g -Wall

ProjectB: ProjectB.o Location.o
	$(CPP) $(CPPFLAGS) Location.o ProjectB.o -o ProjectB

Location.o: Location.cpp
	$(CPP) $(CPPFLAGS) -c Location.cpp -o Location.o

ProjectB.o: ProjectB.cpp
	$(CPP) $(CPPFLAGS) -c ProjectB.cpp -o ProjectB.o

clean:
	rm -f *.o ProjectB
