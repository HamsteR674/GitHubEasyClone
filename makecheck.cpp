#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

bool CheckFir (const char *dirname)
{
	bool ans = 1;
	chdir (dirname);
	printf("Введено название папки: %s\n", dirname);
	system ("dir");
	printf("\n\n");
	ans = access ("Makefile", 4);
	if (ans == 0)
		printf ("makefile есть \n\n\n");
	else
		printf ("makefile нет \n\n\n");

	if (ans == -1)
		ans = 1;

	return ans;
}

int CheckSec (const char *dirname)
{
	int MakeError, j, i = 0;
	char *Findrus  = NULL;
	char *Findeng  = NULL;
	char *FindRus  = NULL;
	char *FindEng  = NULL;
	char *FindRus2 = NULL;
	char *Findrus2 = NULL;
	char Reqrus[16]  = "останов.";
	char Reqeng[16]  = "error";
	char ReqRus[16]  = "Останов.";
	char ReqEng[16]  = "Error";
	char ReqRus2[16] = "Ошибка";
	char Reqrus2[16] = "ошибка";
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
	else 
		printf ("Работа с логом началась\n\n");

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
		if (Findrus != NULL || Findeng != NULL || FindRus != NULL || FindEng != NULL || FindRus2 != NULL || Findrus2 != NULL)
		{
			cout << "Возникли неполадки при компиляции" << endl;
			return 1;
		}	
		i++;
	}
	if (Findrus == NULL && Findeng == NULL && FindRus == NULL && FindEng == NULL && FindRus2 != NULL && Findrus2 != NULL)
		cout << "Ошибок не обнаружено" << endl;
			
	system ("rm -rf log");
	system ("dir");
	//printf("\n\n");
	chdir("..");
	
	printf("\n\n");
	return MakeError;
}

