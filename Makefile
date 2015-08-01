CPP = g++
CPPFLAGS = -g -Wall

ProjectB: ProjectB.o Location.o
	$(CPP) $(CPPFLAGS) Location.o ProjectB.o -o ProjectB

Location.o: Location.cpp
	$(CPP) $(CPPFLAGS) -c Location.cpp -o Location.o

ProjectB.o: ProjectB.cpp
	$(CPP) $(CPPFLAGS) -c ProjectB.cpp -o ProjectB.o

UnitTests: UnitTests.o Location.o
	$(CPP) $(CPPFLAGS) Location.o UnitTests.o -o UnitTests

UnitTests.o: UnitTests.cpp
	$(CPP) $(CPPFLAGS) -c UnitTests.cpp -o UnitTests.o

test: UnitTests
	UnitTests

clean:
	rm -f *.o ProjectB
