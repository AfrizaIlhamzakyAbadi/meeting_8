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
test_Source: test_Source.o
	g++ test_Source.o -o test_Source.exe

# Target to compile the C++ Test program
test_Source.o: test_Source.cpp
	g++ -c test_Source.cpp -o test_Source.o

# Target to run the Test program
test: test_Source
	./test_Source.exe

# Target to clean up compiled files
clean:
	rm -f Source.o test_Source.o Source.exe test_Source.exe
