/*
USER: zobayer
TASK: KROW
ALGO: simulation
*/

#include <stdio.h>

#define MAX 201
#define F 1
#define S 2

char cell[MAX][MAX];
int col, row, kth, p1, p2;

inline bool inrange(int a, int b, int c)
{
	return (a<=b && b<=c);
}

int check(int si, int sj, int di, int dj)
{
	int i = si, j = sj, k, cnt = 0, prev = cell[si][sj];
	if(!inrange(0, si + (kth-1)*di, row-1) || !inrange(0, sj + (kth-1)*dj, col-1)) return '.';
	for(k=0; k<kth; k++)
	{
		if(cell[i][j] == '.') return '.';
		if(cell[i][j] != prev) return '.';
		cnt += cell[i][j];
		i += di;
		j += dj;
	}
	if(cnt == kth*'o') return 'o';
	else if(cnt == kth*'x') return 'x';
	return '.';
}

int winner()
{
	int i, j, k;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			k = check(i, j, 0, 1);
			if(k=='x') return F;
			else if(k=='o') return S;

			k = check(i, j, 1, 0);
			if(k=='x') return F;
			else if(k=='o') return S;

			k = check(i, j, 1, 1);
			if(k=='x') return F;
			else if(k=='o') return S;

			k = check(i, j, 1, -1);
			if(k=='x') return F;
			else if(k=='o') return S;
		}
	}
	return 0;
}

int main()
{
	int t, i, v;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d", &col, &row, &kth);
		for(i=0; i<row; i++) scanf("%s", cell[i]);
		v = winner();
		if(v == F) p1++;
		else if(v == S) p2++;
	}
	printf("%d:%d\n", p1, p2);
	return 0;
}
