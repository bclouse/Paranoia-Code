main: paranoia.cpp Character.o
	g++ -o hw paranoia.cpp Character.o

classes: Character.cpp
	g++ -c Character.cpp