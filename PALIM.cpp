#include <cstdio> 
#include <cstring> 
#include <cstdlib> 
class Tester{
private:
	char str[100001],sec[99];
	int cnt,n;
public:
	Tester(){cnt=0,n=strlen(gets(str)),gets(sec);}
	inline int getN(){return n;}
	inline bool isSame(int a,int b){return ++cnt<=4*n&&a>=0&&a<n&&b>=0&&b<n?str[a]==str[b]:(printf("ERROR while calling isSame()\n"),exit(1),false);}
	inline void answer(int a){printf("%d\n%s\n",a,sec),exit(0);}
}tester;
inline int getN(){return tester.getN();}
inline bool isSame(int a,int b){return tester.isSame(a,b);}
inline void answer(int a){tester.answer(a);}
#define tester _tester_

/*
USER: zobayer
TASK: PALIM
ALGO: manacher
*/

#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector< int > lengths;
	int i, j, palLen, longest, seqLen, s, e, d, found, cnt = 0;
	i = palLen = longest = 0;
	seqLen = getN();
	while(i < seqLen)
	{
		if(i > palLen && isSame(i - palLen - 1, i))
		{
			palLen += 2;
			i += 1;
			cnt++;
			continue;
		}
		longest = max(longest, palLen);
		lengths.push_back(palLen);
		s = lengths.size() - 2;
		e = s - palLen;
		found = 0;
		for(j=s; j>e; j--)
		{
			d = j - e - 1;
			if(lengths[j] == d)
			{
				palLen = d;
				found = 1;
				break;
			}
			longest = max(longest, palLen);
			lengths.push_back(min(d, lengths[j]));
		}
		if(!found)
		{
			palLen = 1;
			i++;
		}
	}
	lengths.push_back(palLen);
	longest = max(longest, palLen);
	answer(longest);
	return 0;
}
