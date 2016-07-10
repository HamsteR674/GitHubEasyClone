#ifndef filescan_h
#define filescan_h
using namespace std;

struct Person { 
string name; 
string github; 
string group; 
string repository; 
string catalog;
string grc;
}; 

extern Person group[500];
extern int group_max_num;

int filescan();

#endif