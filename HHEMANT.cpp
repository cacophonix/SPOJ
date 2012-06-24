/*
USER: zobayer
TASK: HHEMANT
ALGO: ad-hoc
*/

#include <stdio.h>

#define MSG 1111
#define IMG 11111

char msg[MSG], img[IMG];
int sto[3*MSG];

inline void store(int v, int &j)
{
	sto[j++] = v & 3; v >>= 2;
	sto[j++] = v & 3; v >>= 2;
	sto[j++] = v & 3;
}

int main()
{
	int t, n, i, j, k, cnt, v, tot;
	scanf("%d\n", &t);
	while(t--)
	{
		gets(msg);
		for(i=j=0; msg[i]; i++)
		{
			if(msg[i]==' ') store(0, j);
			else if(msg[i]>='A' && msg[i]<='Z') store(msg[i]-'A'+1, j);
			else if(msg[i]>='a' && msg[i]<='z') store(msg[i]-'a'+27, j);
			else if(msg[i]>='0' && msg[i]<='9') store(msg[i]-'0'+53, j);
		}
		tot = j;
		scanf("%d\n", &n);
		for(i=k=0; i<n; i++)
		{
			gets(img);
			for(j=v=cnt=0; img[j]; j++)
			{
				if(img[j]>='0' && img[j]<='9')
				{
					v = v*10 + img[j]-'0';
					cnt++;
					if(cnt==3)
					{
						if(k < tot) v = (v & 252) | sto[k++];
						else v = (v & 252) | 3;
						printf("%03d", v);
						cnt = v = 0;
					}
				}
			}
			printf("\n");
		}
	}
	return 0;
}
