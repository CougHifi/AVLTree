# This is an example makefile. A makefile is a file that contains
# a set of directives to automate the build of the software.
# This is a very basic form of a makefile! We will add more to our makefiles in the future!
prog: main.o
	g++ -Wall -std=c++11 main.o  -o ourprog

main.o: main.cpp 
	g++ -Wall -std=c++11 -c main.cpp 



clean: 
	-rm *.o

run:
	@./ourprog