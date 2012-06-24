/*
USER: zobayer
TASK: SBANK
ALGO: sorting, mapping
*/

#include <map>
#include <string>
#include <cstdio>
using namespace std;

int main() {
	int n, i, t;
	char str[100];
	for(scanf("%d", &t); t; t--) {
		map<string, int> M;
		map<string, int> :: iterator it;
		scanf("%d\n", &n);
		for(i=0;i<n;i++) {
			gets(str);
			M[(string)str]++;
		}
		for(it=M.begin(); it!=M.end(); it++) printf("%s%d\n",(*it).first.c_str(), (*it).second); 
		if(t>1) printf("\n");
	}
	return 0;
}
