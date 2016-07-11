#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <iostream>
#include "makecheck.hpp"
#include "maketestrepeat.hpp"
using namespace std;

bool CheckFir (const char *dirname)
{
	string buf;
	setlocale(LC_ALL, "rus"); 
	chdir("..");
	fstream file;
	file.open("../../../GHLog.txt", fstream::out|fstream::app);
	chdir("github_clones");
	bool ans = 1;
	chdir (dirname);
	file << "catalog: " << dirname << endl;
	printf("catalog: %s\n", dirname);
	system ("dir");
	printf("\n\n");
	ans = access ("Makefile", 4);
	if (ans == 0){
		printf ("makefile есть \n\n\n");
		buf += " has makefile\n";
		//writelog(buf);
	}
	else{
		printf ("makefile нет \n\n\n");
		buf += " no makefile\n";
		//writelog(buf);
	}
	if (ans == -1)
		ans = 1;
	file << buf << endl;
	//writelog(buf);
	file.close();
	return ans;
}

int CheckSec (const char *dirname)
{
	string buf;
	fstream file;
	file.open("../../GHLog.txt", fstream::out|fstream::app);
	int MakeError, j, i = 0;
	char *Findrus  = NULL;
	char *Findeng  = NULL;
	char *FindRus  = NULL;
	char *FindEng  = NULL;
	char *FindRus2 = NULL;
	char *Findrus2 = NULL;
	char *Findeng2 = NULL;
	char Reqrus[16]  = "останов.";
	char Reqeng[16]  = "error";
	char ReqRus[16]  = "Останов.";
	char ReqEng[16]  = "Error";
	char ReqRus2[16] = "Ошибка";
	char Reqrus2[16] = "ошибка";
	char Reqeng2[16] = "fatal";
	char AllText[100];
	chdir (dirname);
	FILE *Log = NULL;
	system ("dir");
	printf("\n\n");
	MakeError = system ("make 2> log");
	printf("\n\n");
	Log = fopen ("log", "r");

	if (Log == NULL)
		MakeError = -1;
	else {
		printf ("Работа с логом началась\n\n");
		buf += " working with log\n ";
		//writelog(buf);
	}

	while (getc (Log) > 0 && i < 100)
	{
		cout << i << endl;
		fscanf (Log, "%s", AllText);
		Findrus = strstr (AllText, Reqrus);
		Findeng = strstr (AllText, Reqeng);
		FindRus = strstr (AllText, ReqRus);
		FindEng = strstr (AllText, ReqEng);
		FindRus2 = strstr (AllText, ReqRus2);
		Findrus2 = strstr (AllText, Reqrus2);
		Findeng2 = strstr (AllText, Reqeng2);
		if (Findrus != NULL || Findeng != NULL || FindRus != NULL || FindEng != NULL || FindRus2 != NULL || Findrus2 != NULL || Findeng2 != NULL)
		{
			cout << "Возникли неполадки при компиляции" << endl;
			buf += "Compilation fault\n";

			return 1;
		}	
		i++;
	}
	if (Findrus == NULL && Findeng == NULL && FindRus == NULL && FindEng == NULL && FindRus2 != NULL && Findrus2 != NULL && Findeng2 != NULL){
		cout << "Ошибок не обнаружено" << endl;
		buf += "No error found\n";
	}
	//writelog(buf);
	file << buf << endl;
	//system ("rm -rf log");
	system ("dir");
	chdir("..");
	printf("\n\n");
	file.close();
	return MakeError;
}

