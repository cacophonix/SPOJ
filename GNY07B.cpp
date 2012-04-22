/*
USER: zobayer
TASK: GNY07B
ALGO: ad-hoc
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t, x;
	double val;
	string unit;
	ios::sync_with_stdio(false);
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(4);
	cin >> t;
	for(x=1; x<=t; x++)
	{
		cin >> val >> unit;
		if(unit=="kg") cout << x << ' ' << val * 2.2046 << " lb\n";
		else if(unit=="lb") cout << x << ' ' << val * 0.4536 << " kg\n";
		else if(unit=="l") cout << x << ' ' << val * 0.2642 << " g\n";
		else if(unit=="g") cout << x << ' ' << val * 3.7854 << " l\n";
	}
	return 0;
}
