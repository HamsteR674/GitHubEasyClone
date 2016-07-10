#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <string.h> 
#include <iostream> 
#include <fstream> 
#include "makecheck.hpp" 
#include "filescan.hpp"


int filescan(){ 
setlocale(LC_ALL, "rus"); 
ifstream fin("gitclonefile.csv"); 
int z = 0;
while(!fin.eof()){
z = z+1;
getline(fin, group[z].name, ',');
//cout << "name = " << group[z].name << endl;
getline(fin, group[z].group, ',');
//cout << "group = "<< group[z].group << endl;
getline(fin, group[z].github, ',');
//cout << "github = "<< group[z].github << endl;
getline(fin, group[z].repository, ',');
//cout << "repository = "<< group[z].repository << endl;
getline(fin, group[z].catalogue, ',');
//cout << "catalogue = "<< group[z].catalogue << endl;
group[z].grc += group[z].github;
group[z].grc += "/" ;
group[z].grc += group[z].repository;
group[z].grc += "/" ;
group[z].grc += group[z].catalogue;
//cout << "grc = "<< group[z].grc << endl;
} 
group_max_num = z;
cout << z << endl;
return 0;
} 
