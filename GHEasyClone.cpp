#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include "makecheck.hpp"
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

int main()
{
	bool maketest;
	string ks;
	const char *kcc;
	string s ;
	cout <<  "enter repository i.e. 'owner_name/repo_name':" <<  endl; 
	cin >> s;
	kcc = findrepname(s);
	ks = strdup(kcc);
	system("git clone http://github.com/" + s);
	cout << "stole " <<  s << endl; 
	maketest = CheckFir(kcc);
	cout << maketest << " done first check" << endl;
	if (maketest == 0)
	{
		int build = CheckSec(kcc);
		if (build >= 1)
		{
			cout << build << " failed second check, trying to reclone" << endl;
			chdir("..");
			system("rm -rf " + ks);
			system("git clone http://github.com/" + s);
			cout << "cloned #2 " <<  s << endl; 
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
		chdir("..");
		system("rm -rf " + ks);
		system("git clone http://github.com/" + s);
		cout << "cloned #2 " <<  s << endl; 
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
