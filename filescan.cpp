#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <string.h> 
#include <iostream> 
#include <fstream> 
#include "makecheck.hpp" 
#include "filescan.hpp"
Person group[500];
int group_max_num = 0;


int filescan(){ 
setlocale(LC_ALL, "rus"); 
ofstream file("/home/hamstermain/quest/GHLog.txt");
ifstream fin("gitclonefile.csv");
cout << "found gitclonefile" << endl;
file << "found gitclonefile" << endl;

int z = 0;
while(!fin.eof()){
getline(fin, group[z].name, ',');
//cout << "name = " << group[z].name << endl;
getline(fin, group[z].group, ',');
//cout << "group = "<< group[z].group << endl;
getline(fin, group[z].github, ',');
//cout << "github = "<< group[z].github << endl;
getline(fin, group[z].repository, ',');
//cout << "repository = "<< group[z].repository << endl;
getline(fin, group[z].catalog, ',');
//cout << "catalog = "<< group[z].catalog << endl;
group[z].grc += group[z].github;
group[z].grc += "/" ;
group[z].grc += group[z].repository;
//group[z].grc += "/" ;
//group[z].grc += group[z].catalog;
cout << "grc = " << group[z].grc << endl;
file << "grc = " << group[z].grc << endl;
z = z+1;
} 
group_max_num = z;
cout << group_max_num << endl;
file << group_max_num << endl;
file.close();
return 0;
} 
