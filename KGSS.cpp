/*
USER: zobayer
TASK: KGSS
ALGO: segment tree
*/

#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 131072
#define MAXT 262144

struct T { int m1, m2; } Tree[MAXT];
int Array[MAXN];

void init(int Node, int i, int j)
{
	if(i==j)
	{
		Tree[Node].m1 = Array[i];
		Tree[Node].m2 = 0;
		return;
	}
	int m = (i+j)/2, t[4];
	init(2*Node, i, m);
	init(2*Node+1, m+1, j);
	t[0] = Tree[2*Node].m1, t[1] = Tree[2*Node].m2;
	t[2] = Tree[2*Node+1].m1, t[3] = Tree[2*Node+1].m2;
	sort(t, t+4);
	Tree[Node].m1 = t[3], Tree[Node].m2 = t[2];
}

void update(int Node, int i, int j, int val, int idx)
{
	if(i==j)
	{
		Array[i] = val;
		Tree[Node].m1 = val;
		Tree[Node].m2 = 0;
		return;
	}
	int m = (i+j)/2, t[4];
	if(idx <= m) update(2*Node, i, m, val, idx);
	else update(2*Node+1, m+1, j, val, idx);
	t[0] = Tree[2*Node].m1, t[1] = Tree[2*Node].m2;
	t[2] = Tree[2*Node+1].m1, t[3] = Tree[2*Node+1].m2;
	sort(t, t+4);
	Tree[Node].m1 = t[3], Tree[Node].m2 = t[2];
}

void query(int Node, int i, int j, int s, int e, int &max1, int &max2)
{
	if((s==i && e==j) || i==j)
	{
		max1 = Tree[Node].m1, max2 = Tree[Node].m2;
		return;
	}
	int m = (i+j)/2, t[4];
	if(e <= m)
		query(2*Node, i, m, s, e, max1, max2);
	else if(s > m)
		query(2*Node+1, m+1, j, s, e, max1, max2);
	else
	{
		query(2*Node, i, m, s, m, max1, max2);
		t[0] = max1, t[1] = max2;
		query(2*Node+1, m+1, j, m+1, e, max1, max2);
		t[2] = max1, t[3] = max2;
		sort(t, t+4);
		max1 = t[3];
		max2 = t[2];
	}
}

int main()
{
	int N, Q, x, y, i, max1, max2;
	char comm[4];
	scanf("%d", &N);
	for(i = 0; i < N; i++)
		scanf("%d", &Array[i]);
	init(1, 0, N-1);
	scanf("%d", &Q);
	for(i = 0; i < Q; i++)
	{
		scanf("%s %d %d", comm, &x, &y);
		if(comm[0]=='U')
			update(1, 0, N-1, y, x-1);
		else
		{
			query(1, 0, N-1, x-1, y-1, max1, max2);
			printf("%d\n", max1 + max2);
		}
	}
	return 0;
}
