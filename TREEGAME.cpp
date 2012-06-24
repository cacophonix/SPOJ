/*
USER: zobayer
TASK: TREEGAME
ALGO: divide and conquer
*/

#define _CRT_SECURE_NO_WARNINGS 1
#define DEBUG if(0)
#define NMAX (1<<16)
#define TMAX (1<<17)
#define ZERO 1
#define ONE 2

#include <cstdio>
using namespace std;

int TREE[TMAX];

// all index 1 based
// node, index, required, left, right
void visit(int node, int idx, int req, int left, int right)
{
	if(left==right)
	{
		TREE[node] = req;
		printf("%d", req-1);
		return;
	}
	int L = TREE[2*node], R = TREE[2*node+1], M = (left+right)/2, T;
	if(req==ZERO) T = ONE;
	else if(!L && !R) T = ONE;
	else T = ZERO;
	if(idx <= M) visit(2*node, idx, T, left, M);
	else visit(2*node+1, idx, T, M+1, right);
	L = TREE[2*node], R = TREE[2*node+1];
	if(L*R) TREE[node] = req;
}

int main()
{
	DEBUG freopen("in.txt", "r", stdin);
	int i, n, idx, d;
	scanf("%d", &d);
	n = (1<<d);
	for(i=1; i<n; i++)
	{
		if(i>1) printf(" ");
		scanf("%d", &idx);
		// node, index, required, left, right
		visit(1, idx, ONE, 1, n);
	}
	// dump last input
	scanf("%d", &idx);
	printf("\n");
	return 0;
}
