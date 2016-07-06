all:  quest.o makecheck.o maketestrepeat.o
	g++ -c quest.cpp
	g++ -c makecheck.cpp
	g++ -c maketestrepeat.cpp
	g++ -o GHEasyClone quest.o makecheck.o maketestrepeat.o

clean:
	rm -f *.o