CPP = g++
CPPFLAGS = -g -Wall

ProjectB: ProjectB.o Location.o functions.o
	$(CPP) $(CPPFLAGS) functions.o Location.o ProjectB.o -o ProjectB

functions.o: functions.cpp
	$(CPP) $(CPPFLAGS) -c functions.cpp -o functions.o

Location.o: Location.cpp
	$(CPP) $(CPPFLAGS) -c Location.cpp -o Location.o

ProjectB.o: ProjectB.cpp
	$(CPP) $(CPPFLAGS) -c ProjectB.cpp -o ProjectB.o

UnitTests: UnitTests.o functions.o Location.o
	$(CPP) $(CPPFLAGS) functions.o Location.o UnitTests.o -o UnitTests

UnitTests.o: UnitTests.cpp
	$(CPP) $(CPPFLAGS) -c UnitTests.cpp -o UnitTests.o

test: UnitTests
	./UnitTests

clean:
	rm -f *.o ProjectB UnitTests
