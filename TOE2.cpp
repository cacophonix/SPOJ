/*
USER: zobayer
TASK: TOE2
ALGO: simulation
*/

#include <stdio.h>
#include <string.h>

char board[3][4];

void getwinner(int &winx, int &wino)
{
	int i, j, cnt, x, o;
	x = o = 0;
	for(i=0;i<3;i++)
	{
		cnt = 0;
		for(j=0;j<3;j++)
			cnt += board[i][j];
		if(cnt=='X'*3) x++;
		else if(cnt=='O'*3) o++;
	}
	for(i=0;i<3;i++)
	{
		cnt = 0;
		for(j=0;j<3;j++)
			cnt += board[j][i];
		if(cnt=='X'*3) x++;
		else if(cnt=='O'*3) o++;
	}
	for(i=j=cnt=0; i<3; i++, j++)
		cnt += board[i][j];
	if(cnt=='X'*3) x++;
	else if(cnt=='O'*3) o++;
	for(i=0,j=2,cnt=0; i<3; i++, j--)
		cnt += board[i][j];
	if(cnt=='X'*3) x++;
	else if(cnt=='O'*3) o++;
	winx = x;
	wino = o;
}

int main()
{
	int i, j, x, o, d, winx, wino;
	char str[15];
	while(scanf("%s",str)==1)
	{
		if(!strcmp(str,"end")) break;
		for(i=0; i<3; i++)
		{
			strncpy(board[i],&str[i*3],3);
			board[i][3] = 0;
		}
		x = o = d = 0;
		for(i=0;i<3;i++)
			for(j=0;j<3;j++)
				if(board[i][j]=='X') x++;
				else if(board[i][j]=='O') o++;
				else d++;
		getwinner(winx,wino);
		if(o>x||(o==x&&winx)||x>o+1||(x==o+1&&wino)||winx>2||wino>1||(winx && wino))
			printf("invalid\n");
		else if((winx && !wino) || (!winx && wino)) printf("valid\n");
		else if(!winx && !wino && !d) printf("valid\n");
		else printf("invalid\n");
	}
	return 0;
}
