/*
USER: zobayer
TASK: CNEASY
ALGO: geometry
*/

#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

#define MAX 1001
#define eps 1e-10

int main()
{
	int t, n, time, i;
	char s[50];
	double a[MAX], minA, sec, temp;
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin >> s >> a[i];
		sort(a,a+n);
		minA=a[n-1]-a[0];
		for(i=1;i<n;i++)
		{
			temp=(360.00-a[i]+a[i-1]);
			minA = min(minA, temp);
		}
		sec = minA*12.0;
		time = (int)(ceil(sec)+eps);
		cout<<time<<endl;
	}
	return 0;
}
