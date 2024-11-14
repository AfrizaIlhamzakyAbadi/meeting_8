# Target to compile the object file
Source: Source.o
	g++ Source.o -o Source.exe

# Target to compile the C++ program
Source.o: Source.cpp
	g++ -c Source.cpp -o Source.o

# Target to run the program (interactively)
run: Source
	./Source.exe

# Target to compile the object Test file
SourceTest: SourceTest.o
	g++ SourceTest.o -o SourceTest.exe

# Target to compile the C++ Test program
SourceTest.o: SourceTest.cpp
	g++ -c SourceTest.cpp -o SourceTest.o

# Target to run the Test program
test: SourceTest
	./SourceTest.exe

# Target to clean up compiled files
clean:
	rm -f Source.o SourceTest.o Source.exe SourceTest.exe
