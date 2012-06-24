/*
USER: zobayer
TASL: BINGO
ALGO: ad-hoc
*/

#include <set>
#include <string>
#include <cctype>
#include <iostream>
#include <sstream>
using namespace std;

void getlower(string &s)
{
	int i, len = s.size();
	for(i=0; i<len; i++)
	{
		if(isalpha(s.at(i))) s.at(i) = islower(s.at(i))? s.at(i)-32 : s.at(i);
		else s.at(i) = ' ';
	}
}

int gcd(int a, int b)
{
	if(!b) return a;
	else return gcd(b,a%b);
}

int main()
{
	int game=0, total=0, g;
	string line, str;
	set< string > S;
	ios::sync_with_stdio(false);
	while(getline(cin,line))
	{
		getlower(line);
		stringstream ss(line);
		while(ss >> str)
		{
			if(str=="BULLSHIT")
			{
				total += S.size();
				game++;
				S.clear();
			}
			else S.insert(str);
		}
	}
	g = gcd(total, game);
	cout << total/g << " / " << game/g << endl;
	return 0;
}


