/*
USER: zobayer
TASK: WORDCNT
ALGO: ad-hoc
*/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
	string line, s;
	int t, best, len, prlen, wrdcnt;
	ios::sync_with_stdio(false);
	cin >> t;
	getline(cin, s);
	while(t--) {
		getline(cin, line);
		best = prlen = wrdcnt = 0;
		stringstream ss(line);
		while(ss >> s) {
			len = s.size();
			if(len==prlen) wrdcnt++;
			else {
				if(wrdcnt > best) best = wrdcnt;
				wrdcnt = 1;
				prlen = len;
			}
		}
		if(wrdcnt > best) best = wrdcnt;
		cout << best << endl;
	}
	return 0;
}
