/*
USER: zobayer
TASK: BST
ALGO: binary tree construction
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <set>
#include <ios>
using namespace std;

#define MAX 300003

long long flag[MAX][3]; // 0 depth, 1 left, 2 right

int main()
{
//	freopen("in1.txt", "r", stdin);
	set< int > L;
	set< int > :: iterator it;
	int n, q;
	long long c = 0;
	scanf("%d%d", &q, &n);
	L.insert(L.begin(),n);
	printf("%d\n", c);
	while(--q)
	{
		scanf("%d", &n);
		it = L.lower_bound(n);
		if(it==L.end())
		{
			L.insert(it,n);
			it--; it--;
			flag[*it][2] = 1;
			flag[n][0] = flag[*it][0]+1;
		}
		else if(it==L.begin())
		{
			L.insert(it,n);
			flag[*it][1] = 1;
			flag[n][0] = flag[*it][0]+1;
		}
		else
		{
			L.insert(it,n);
			it--;it--;
			if(!flag[*it][2])
			{
				flag[*it][2] = 1;
				flag[n][0] = flag[*it][0]+1;
			}
			else
			{
				it++;it++;
				flag[*it][1] = 1;
				flag[n][0] = flag[*it][0]+1;
			}
		}
		c += flag[n][0];
		printf("%lld\n", c);
	}
	return 0;
}

