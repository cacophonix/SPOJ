/*
USER: zobayer
TASK: PQUEUE
ALGO: heap
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define pii pair< int, int >

int main()
{
	int test, n, myjob, prio, i, t;
	ios::sync_with_stdio(false);
	cin >> test;
	while(test--)
	{
		queue< pii > Q;
		priority_queue< int > PQ;
		cin >> n >> myjob;
		for(i=0; i<n; i++)
		{
			cin >> prio;
			PQ.push(prio);
			Q.push(pii(i,prio));
		}
		t = 0;
		while(!Q.empty())
		{
			i = Q.front().first;
			prio = Q.front().second;
			Q.pop();
			if(prio != PQ.top()) Q.push(pii(i,prio));
			else
			{
				t++;
				PQ.pop();
				if(i==myjob) break;
			}
		}
		cout << t << endl;
	}
	return 0;
}