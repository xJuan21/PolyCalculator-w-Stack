CC=g++ -c -g -Wall -ansi -std=c++11 -pedantic 

runMe: main.o Term.o Token.o Polynomial.o
	g++ -o runMe main.o Term.o Token.o Polynomial.o
	
main.o: main.cpp Term.hpp Polynomial.hpp MyStack.hpp
	$(CC)  main.cpp
	
Term.o: Term.cpp Term.hpp
	$(CC) Term.cpp
	
Token.o: Token.cpp Token.hpp
	$(CC) Token.cpp

Polynomial.o: Polynomial.cpp Polynomial.hpp
	$(CC) Polynomial.cpp
