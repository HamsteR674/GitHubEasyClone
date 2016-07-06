all:  GitHubEasyClone.o makecheck.o maketestrepeat.o
	g++ -c GitHubEasyClone.cpp
	g++ -c makecheck.cpp
	g++ -c maketestrepeat.cpp
	g++ -o GHEasyClone GitHubEasyClone.o makecheck.o maketestrepeat.o

clean:
	rm -f *.o
