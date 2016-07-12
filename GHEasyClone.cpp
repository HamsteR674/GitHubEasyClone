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


int main() // struct group included in filescan.hpp
{
	fstream file;
	setlocale(LC_ALL, "rus"); 
	fstream report;
	string buf;
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
		system("git clone http://github.com/" + group[z].grc + " 2> log.txt" );
		chdir("..");
		file.open("GHLog.txt", fstream::out|fstream::app);
		cout << "stole " <<  group[z].grc << endl; 
		buf = "stole ";
		buf += group[z].grc;
		file << buf << endl;
		file << "rep number " << z << endl;
		file.close();
		chdir("github_clones");
		report.open("../final_report.txt", fstream::out|fstream::app);
		report << group[z].name << ", " << group[z].group << ", " << group[z].github << ", " << group[z].repository << ", " << group[z].catalog << ", ";
		report.close();
		clone_test_repeat(kcc, group[z].repository, group[z].grc); //maketestrepeat.cpp	
	}
	file.open("GHLog.txt", fstream::out|fstream::app);

	file << "_______________________________________" << endl << endl;
	return 0; 
}