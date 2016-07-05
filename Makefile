all:  quest.o makecheck.o
	g++ -c quest.cpp
	g++ -c makecheck.cpp
	g++ -o GHEasyClone quest.o makecheck.o

clean:
	rm -f *.o
