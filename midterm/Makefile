OBJECTS=List.o Node.o
CXXFLAGS=
LDFLAGS=
CXX=g++

main: main.o $(OBJECTS)
	$(CXX) -o main main.o $(OBJECTS)

tests: tests.o $(OBJECTS)
	g++ -o tests tests.o $(OBJECTS)

main.o: main.cpp List.h

List.o: List.cpp List.h Node.h

Node.o: Node.cpp Node.h

clean:
	rm -f main.o tests.o $(OBJECTS)