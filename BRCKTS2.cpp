/*
USER: zobayer
TASK: BRCKTS2
ALGO: recursion
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define i64 long long
#define MAX 350000

char str[MAX+1];

void recur(i64 &h, i64 &w, int d, int &pos, i64 &area)
{
	i64 maxH = 0, newW, newH;
	pos++;
	while(str[pos]=='(')
	{
		newH = newW = 1;
		recur(newH, newW, d+1, pos, area);
		w += newW + 1;
		maxH = max(newH, maxH);
		pos++;
	}
	h = maxH + 1;
	if(d & 1) area += w * h;
	else area -= w*h;
}

int main()
{
	int t, len, i;
	i64 w, h, area;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%s", str);
		len = strlen(str);
		area = 0;
		for(i=0; i<len; i++)
		{
			h = w = 1;
			recur(h, w, 1, i, area);
		}
		printf("%lld\n", area);
	}
	return 0;
}

