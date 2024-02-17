all: Main.exe

Main.exe: Main.o BinaryTree.o FileIO.o
	g++ -std=c++11 -o Main.exe Main.o BinaryTree.o FileIO.o 

Main.o: Main.cpp
	g++ -std=c++11 -c Main.cpp
BinaryTree.o: BinaryTree.cpp BinaryTree.h Node.h
	g++ -std=c++11 -c BinaryTree.cpp
FileIO.o: FileIO.cpp FileIO.h
	g++ -std=c++11 -c FileIO.cpp

clean:
	rm -rf *.o
