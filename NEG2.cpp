/*
USER: zobayer
TASK: NEG2
ALGO: base conversion
*/

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define OFF ios::sync_with_stdio(false)

string negabinary(int i)
{
	
	int reminder;
	string digits;
	while(i != 0)
	{
		reminder = i % -2;
		i /= -2;
		if(reminder < 0)
		{
			i++;
			reminder += 2;
		}
		digits.push_back(reminder+'0');
	}
	if(digits.size()==0) digits.push_back('0');
	else reverse(digits.begin(),digits.end());
	return digits;
}

int main()
{
	OFF;
	int n;
	while(cin>>n) cout << negabinary(n) << endl;
	return 0;
}
