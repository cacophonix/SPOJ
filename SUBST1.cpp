/*
USER: zobayer
TASK: SUBST1
ALGO: suffix array
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char str[50005];
int s[50005];
long long l;

int cmp(const void *a,const void *b) {
	return (strcmp((str+ *((int*)a)),(str+ *((int*)b))));
}

void suffix_array(int n) {
	int i;
	for(i=0;i<n;i++) s[i]=i;
	qsort(s,n,sizeof(int),cmp);
}

long long lcp(void) {
	int i, j, k;
	long long count = 0;
	char *z = str, *y = str;
	int p[50005] = {0};
	for(i=1,k=0;i<l;i++,k=0) {
		z = str + s[i];
		y = str + s[i-1];
		while(*z==*y) {
			p[i]++;
			z++;
			y++;
		}
		count += p[i];
	}
	return count;
}

int main() {
	int n, i, j, c;
	scanf("%d",&n);
	while(n--) {
		scanf("%s",str);
		l = strlen(str);
		suffix_array(l);
		c = lcp();
		printf("%lld\n", (l*(l+1)/2)-c);
	}
	return 0;
}
