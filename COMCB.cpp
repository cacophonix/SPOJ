/*
USER: zobayer
TASK: COMCB
ALGO: flood fill
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>
#include <cstring>
#include <utility>
using namespace std;

#define pii pair<int,int>
#define F first
#define S second
#define MAX 26

int row, col, flag;

inline bool inrange(int a, int b, int c)
{
	return (a<=b && b<c);
}

void visit(int i, int j, bool board[][MAX], int cnt, pii res[])
{
	res[cnt-1] = pii(i, j);
	if(cnt==row*col)
	{
		flag = 1;
		for(int k=0; k<row*col; k++)
			printf("%c%d", 'A' + res[k].F, 1 + res[k].S);
		printf("\n");
		return;
	}
	// up-left
	if(!flag && inrange(0,i-2,row) && inrange(0,j-1,col) && !board[i-2][j-1])
	{
		board[i-2][j-1] = 1;
		visit(i-2, j-1, board, cnt+1, res);
		board[i-2][j-1] = 0;
	}
	// up-right
	if(!flag && inrange(0,i-2,row) && inrange(0,j+1,col) && !board[i-2][j+1])
	{
		board[i-2][j+1] = 1;
		visit(i-2, j+1, board, cnt+1, res);
		board[i-2][j+1] = 0;
	}
	// left-up
	if(!flag && inrange(0,i-1,row) && inrange(0,j-2,col) && !board[i-1][j-2])
	{
		board[i-1][j-2] = 1;
		visit(i-1, j-2, board, cnt+1, res);
		board[i-1][j-2] = 0;
	}
	// right-up
	if(!flag && inrange(0,i-1,row) && inrange(0,j+2,col) && !board[i-1][j+2])
	{
		board[i-1][j+2] = 1;
		visit(i-1, j+2, board, cnt+1, res);
		board[i-1][j+2] = 0;
	}
	// left-down
	if(!flag && inrange(0,i+1,row) && inrange(0,j-2,col) && !board[i+1][j-2])
	{
		board[i+1][j-2] = 1;
		visit(i+1, j-2, board, cnt+1, res);
		board[i+1][j-2] = 0;
	}
	// right-down
	if(!flag && inrange(0,i+1,row) && inrange(0,j+2,col) && !board[i+1][j+2])
	{
		board[i+1][j+2] = 1;
		visit(i+1, j+2, board, cnt+1, res);
		board[i+1][j+2] = 0;
	}
	// down-left
	if(!flag && inrange(0,i+2,row) && inrange(0,j-1,col) && !board[i+2][j-1])
	{
		board[i+2][j-1] = 1;
		visit(i+2, j-1, board, cnt+1, res);
		board[i+2][j-1] = 0;
	}
	// down-right
	if(!flag && inrange(0,i+2,row) && inrange(0,j+1,col) && !board[i+2][j+1])
	{
		board[i+2][j+1] = 1;
		visit(i+2, j+1, board, cnt+1, res);
		board[i+2][j+1] = 0;
	}
}

inline void dfs(int i, int j, pii res[])
{
	bool board[MAX][MAX] = {0};
	board[i][j] = 1;
	visit(i, j, board, 1, res);
}

bool getres(pii res[])
{
	int i, j;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			flag = 0;
			dfs(i, j, res);
			if(flag) return true;
		}
	}
	return false;
}

int main()
{
	int t;
	pii res[30];
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &col, &row);
		if(!getres(res)) printf("-1\n");
	}
	return 0;
}
