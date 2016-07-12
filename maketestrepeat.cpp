#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include "makecheck.hpp"
#include "maketestrepeat.hpp"
using namespace std;

int system(string cmd)
{
return system(cmd.c_str());
}

/*const char * findrepname(string s){
	string k;
	const char *kc;
	int e;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '/')
		{
			e = i+1;
		}
	}
	for (int i = 0; i < s.size() - e; i++)
		k += s[e + i];
		kc = k.c_str();
	return kc;
}*/

void reclonegit(string ks, string s){
	fstream file;
	file.open("../../GHLog.txt", fstream::out|fstream::app);
	chdir("..");
	system("rm -rf " + ks);
	system("mkdir " + ks);
	system("git clone http://github.com/" + s);
	cout << "cloned #2 " << s << endl; 
	file << "cloned #2 " << s << endl; 
}

int writelog(string s){
	fstream file;
	file.open("../GHLog.txt", fstream::out|fstream::app);
	file << s << endl;
	file.close();
	return 0;

}

int clone_test_repeat(const char *kcc, string ks, string s){
string buf;
bool maketest = CheckFir(kcc);
fstream file;
fstream report;
	 file.open("../../GHLog.txt", fstream::out|fstream::app);
	 report.open("../../final_report.txt", fstream::out|fstream::app);
	cout << maketest << " done first check" << endl;
	buf += "done first check\n";
	if (maketest == 0)
	{
		report << " 1st ok,";
		int build = CheckSec(kcc); //makecheck.cpp
		if (build >= 1)
		{
			cout << build << " failed second check, trying to reclone" << endl;
			buf += " failed second check, trying to reclone\n";
			reclonegit(ks, s);
			maketest = CheckFir(kcc); //makecheck.cpp
			if (maketest == 0)
			{
				int build = CheckSec(kcc); //makecheck.cpp
				
				if (build >= 1)
				{
					cout << build << " failed second check, can't make" << endl;
					buf += " failed second check, can't make\n";
					report << " 2nd NO, failed" << endl;

			}
				else{
					cout << "now " << kcc <<" is working" << endl;
					buf += " now it works\n";
					report << " 2nd ok, all good" << endl;
				}
			}
		}
		else{
			cout << build << " done second check, all good" << endl;
			buf += " done second check, all good\n";
			report << " 2nd ok, all good" << endl;

		}
	}
	else 
	{

		cout << "no makefile, trying to reclone" << endl;
		buf += " no makefile, trying to reclone\n";
		reclonegit(ks, s);
		maketest = CheckFir(kcc); //makecheck.cpp
		if (maketest == 0)
		{
			int build = CheckSec(kcc); //makecheck.cpp

			if (build >= 1){
				cout << build << " failed second check, can't make" << endl;
				buf += " no makefile, can't make\n";
				report << " 2nd NO, failed" << endl;
			}
			else
				cout << "now " << kcc <<" is working" << endl;
				buf += " now it works\n";
				report << " 2nd ok, all good" << endl;
		}
		else
			cout << "no makefile again, can't make" << endl;
			buf += " no makefile again, can't make\n";
			report << " 1st no, failed" << endl;
	}
	file << buf << endl;
	file.close();
	chdir("..");
	return 0;
}