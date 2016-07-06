all:  GHEasyClone.o makecheck.o
	g++ -c GHEasyClone.cpp
	g++ -c makecheck.cpp
	g++ -o GHEasyClone GHEasyClone.o makecheck.o

clean:
	rm -f *.o
