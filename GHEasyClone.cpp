#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fstream>
#include "makecheck.hpp"
#include "maketestrepeat.hpp"
#include "filescan.hpp"
using namespace std;
ofstream file("GHLog.txt");

int main() // struct group included in filescan.hpp
{
	
	string ks;
	const char *kcc;
	string s ;
	filescan();
	system("mkdir github_clones");
	chdir("github_clones");
	for (int z = 0; z < group_max_num; z++)
	{
		kcc = group[z].repository.c_str();
		system("git clone http://github.com/" + group[z].grc /*+ " 2> log.txt" */);
		system("git clone http://github.com/" + group[z].grc + " 2> GHLog.txt" );
		cout << "stole " <<  group[z].grc << endl; 
		file << "stole " <<  group[z].grc << endl; 
		clone_test_repeat(kcc, group[z].repository, group[z].grc); //maketestrepeat.cpp
	}
	file.close();
	return 0; 
}