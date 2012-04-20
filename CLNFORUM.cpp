/*
USER: zobayer
TASK: CLNFORUM
ALGO: ad-hoc
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

static char buff[8192], *ptr = buff;
static char *st, *en;

inline char* getline() {
	while(*ptr < 32) ptr++;
	st = ptr;
	while(ptr < en && *ptr > 31) ptr++;
	*ptr = 0;
	return st;
}

inline void process(char *str, char *tar, char *rep, char *res) {
	int last = 0, k = 0, now, i;
	char temp[128], *p;
	strcpy(temp, str);
	p = strtok(temp, " ");
	while(p) {
		now = p - temp;
		while(last < now) res[k++] = str[last++];
		if(!strcmp(p, tar)) {
			for(i = 0; rep[i]; i++) res[k++] = rep[i];
			for(i = 0; p[i]; i++) last++;
		}
		else for(i = 0; p[i]; i++) res[k++] = str[last++];
		p = strtok(0, " ");
	}
	while(str[last]) res[k++] = str[last++];
	res[k] = 0;
}

int main() {
	char *line, res[1024], temp[1024];
	int t;
	en = buff + fread(buff, 1, 8192, stdin);
	t = atoi(getline());
	while(t--) {
		line = getline();
		process(line, "8", "ate", res);
		strcpy(temp, res);
		process(temp, "w8", "wait", res);
		strcpy(temp, res);
		process(temp, "gr8", "great", res);
		strcpy(temp, res);
		process(temp, "4", "for", res);
		strcpy(temp, res);
		process(temp, "b4", "before", res);
		puts(res);
	}
	return 0;
}