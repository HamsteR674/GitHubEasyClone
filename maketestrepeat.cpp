#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <iostream>
#include "makecheck.hpp"
#include "maketestrepeat.hpp"
using namespace std;

int system(string cmd)
{
return system(cmd.c_str());
}

const char * findrepname(string s){
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
}

void reclonegit(string ks, string s){
	chdir("..");
	system("rm -rf " + ks);
	system("mkdir " + ks);
	system("git clone http://github.com/" + s);
	cout << "cloned #2 " <<  s << endl; 
}

int clone_test_repeat(const char *kcc, string ks, string s){
bool maketest = CheckFir(kcc);

	cout << maketest << " done first check" << endl;
	if (maketest == 0)
	{

		int build = CheckSec(kcc);
		if (build >= 1)
		{
			cout << build << " failed second check, trying to reclone" << endl;
			reclonegit(ks, s);
			maketest = CheckFir(kcc);
			if (maketest == 0)
			{
				int build = CheckSec(kcc);
				
				if (build >= 1)
					cout << build << " failed second check, can't make" << endl;
				else
					cout << "now " << kcc <<" is working" << endl;
			}
		}
		else
			cout << build << " done second check, all good" << endl;
	}
	else 
	{

		cout << "no makefile, trying to reclone" << endl;
		reclonegit(ks, s);
		maketest = CheckFir(kcc);
		if (maketest == 0)
		{
			int build = CheckSec(kcc);

			if (build >= 1)
				cout << build << " failed second check, can't make" << endl;
			else
				cout << "now " << kcc <<" is working" << endl;
		}
		else
			cout << "no makefile again, can't make" << endl;
	}
	return 0;
}