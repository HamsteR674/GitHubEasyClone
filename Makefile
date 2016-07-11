all:  GHEasyClone.o makecheck.o maketestrepeat.o filescan.o
	g++ -o GHEasyClone GHEasyClone.o makecheck.o maketestrepeat.o filescan.o

clean:
	rm -f *.o