/*
USER: zobayer
TASK: MFLAR10
ALGO: ad-hoc
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <string>
using namespace std;

int main() {
	string s, t;
	char ch, fl;
	while(getline(cin, s)) {
		stringstream ss(s);
		ss >> t;
		if(t[0]=='*') break;
		fl = 1;
		ch = toupper(t[0]);
		while(ss >> t) {
			if(toupper(t[0]) != ch) {
				fl = 0;
				break;
			}
		}
		if(fl) puts("Y"); else puts("N");
	}
	return 0;
}
