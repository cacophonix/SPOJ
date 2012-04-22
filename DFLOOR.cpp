/*
USER: zobayer
TASK: DFLOOR
ALGO: greedy
*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

#define D(x) cout << #x " is " << x << endl

int rows, cols;
bool on[15][15];
bool backup[15][15];

#define inside(i, j) (0 <= (i) && (i) < rows && 0 <= (j) && (j) < cols)
#define toggle(x) x = !x

#define mp make_pair

void dance(int i, int j) {
	int di[] = {+0, +0, +1, -1};
	int dj[] = {+1, -1, +0, +0};
	toggle(on[i][j]);
	for(int k = 0; k < 4; k++) {
		if(inside(i + di[k], j + dj[k])) {
			toggle(on[i + di[k]][j + dj[k]]);
		}
	}
}

void print() {
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			cout << on[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	while(cin >> cols >> rows && rows && cols) {
		for(int i = 0; i < rows; i++) {
			for(int j = 0; j < cols; j++) {
				char c;
				cin >> c;
				on[i][j] = (c == '1');
			}
		}
		memcpy(backup, on, sizeof on);
		bool solved = false;
		vector< pair<int, int> > ans(rows * cols + 1);
		for(int set = 0; set < (1 << cols); set++) {
			memcpy(on, backup, sizeof on);
			vector< pair<int, int> > path;
			for(int j=0; j<cols; j++) {
				if(set & (1 << j)) {
					dance(0, j);
					path.push_back(mp(0, j));
				}
			}
			for(int i = 1; i < rows; i++) {
				for(int j = 0; j < cols; j++) {
					if(!on[i-1][j]) {
						dance(i, j);
						path.push_back(mp(i, j));
					}
				}
			}
			bool ok = true;
			for(int i = 0; i < rows; i++) {
				for(int j = 0; j < cols; j++) {
					ok &= on[i][j];
				}
			}
			if(ok && path.size() < ans.size()) {
				ans = path;
				solved = true;
			}
		}
		if(!solved) {
			cout << -1 << endl;
		}
		else {
			cout << ans.size() << endl;
			for(int i = 0; i < ans.size(); i++) {
				cout << ans[i].second + 1 << " " << ans[i].first + 1 << endl;
			}
		}
	}
	return 0;
}
