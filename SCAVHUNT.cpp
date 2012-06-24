/*
USER: zobayer
TASK: SCAVHUNT
ALGO: ad-hoc
*/

#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;

#define OFF ios::sync_with_stdio(false)
#define CLR(x) x.clear()

int main()
{
	OFF;
	map< string, string > M;
	set< string > S;
	string s1, s2;
	int n, i, t, x;
	cin >> t;
	for(x=1; x<=t; x++)
	{
		CLR(M);
		CLR(S);
		cin >> n;
		for(i=0; i<n-1; i++)
		{
			cin >> s1 >> s2;
			M[s1] = s2;
			S.erase(s2);
			S.insert(s1);
		}
		s1 = *S.begin();
		cout << "Scenario #" << x <<":\n";
		cout << s1 << endl;
		for(i=0; i<n-1; i++)
		{
			s2 = M[s1];
			cout << s2 << endl;
			s1 = s2;
		}
		cout << endl;
	}
	return 0;
}
