#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "makecheck.hpp"
#include "maketestrepeat.hpp"
using namespace std;

int main()
{
	string ks;
	const char *kcc;
	string s ;
	cout <<  "enter repository i.e. 'owner_name/repo_name':" <<  endl; 
	cin >> s;
	kcc = findrepname(s);
	ks = strdup(kcc);
	//system("mkdir " + ks);
	system("git clone http://github.com/" + s /*+ " 2> log.txt" */);
	system("git clone http://github.com/" + s + " 2> log.txt" );

	cout << "stole " <<  s << endl; 
	clone_test_repeat(kcc, ks, s);
	return 0;
}
