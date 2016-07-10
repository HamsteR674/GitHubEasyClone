all:  GHEasyClone.o makecheck.o maketestrepeat.o filescan.o
	g++ -c GHEasyClone.cpp
	g++ -c makecheck.cpp
	g++ -c maketestrepeat.cpp
	g++ -c filescan.cpp
	g++ -o GHEasyClone GHEasyClone.o makecheck.o maketestrepeat.o filescan.o

clean:
	rm -f *.o
