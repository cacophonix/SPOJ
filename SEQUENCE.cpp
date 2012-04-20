/*
USER: zobayer
TASK: SEQUENCE
ALGO: sorting
*/

#include <cstdio>
#include <cctype>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;

struct CQ {
	char *hold;
	int t, m, c;
	
	CQ(int n) {
		hold = new char[m=n];
		t = c = 0;
	}
	
	~CQ() {
		delete[] hold;
	}
	
	void nq(char ch) {
		if(c < m) c++;
		hold[t++] = ch;
		if(t==m) t = 0;
	}
	
	void extr(int n, char *ret) {
		if(c < n) {
			ret[0] = 0;
			return;
		}
		ret[n] = 0;
		for(int i = t, l = n; l--; ) {
			i--; if(i < 0) i += m;
			ret[l] = hold[i];
		}
	}
	
	void clr() {
		t = c = 0;
	}
};

int main() {
	CQ q(5);
	char temp[8], ch;
	vector< string > mp[5];
	vector< pair< int, string > > smp[5];
	int i, j, cnt, done;
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while((ch = getchar())!=EOF) {
		if(!isalpha(ch)) {
			q.clr();
			continue;
		}
		q.nq(toupper(ch));
		for(j = 1; j <= 5; j++) {
			q.extr(j, temp);
			if(temp[0]) mp[j-1].push_back(temp);
		}
	}
	for(i = 0; i < 5; i++) sort(mp[i].begin(), mp[i].end());
	for(i = 0; i < 5; i++) {
		for(j = cnt = 1; j < mp[i].size(); j++) {
			if(mp[i][j] == mp[i][j-1]) cnt++;
			else {
				smp[i].push_back(make_pair(-cnt, (string)mp[i][j-1]));
				cnt = 1;
			}
		}
		smp[i].push_back(make_pair(-cnt, (string)mp[i][j-1]));
		sort(smp[i].begin(), smp[i].end());
	}
	for(i = 0; i < 5; i++) {
		if(smp[i].size()==0) continue;
		if(i) puts("");
		printf("Analysis for Letter Sequences of Length %d\n", i+1);
		puts("-----------------------------------------");
		done = 5;
		for(j = 0; done-- && j < smp[i].size(); j++) {
			printf(
				"Frequency = %d, Sequence(s) = (%s",
				-smp[i][j].first, smp[i][j].second.c_str()
			);
			cnt = smp[i][j].first;
			j++;
			while(smp[i][j].first == cnt) {
				printf(",%s", smp[i][j].second.c_str());
				j++;
			}
			puts(")");
			j--;
		}
	}
	return 0;
}
