/*
USER: zobayer
TASK: BALLOON
ALGO: computational geometry
*/

#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }

#define MP(x, y) make_pair(x, y)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;

struct point {
	double x, y, z;
};

point p[6], R1, R2;
vector< pair<point, double> > vp;
int idx[6], flag[6], n;

bool insideRect(const point &p1) {
	if(p1.x < _min(R1.x , R2.x)) return false;
	if(p1.x > _max(R1.x , R2.x)) return false;
	if(p1.y < _min(R1.y , R2.y)) return false;
	if(p1.y > _max(R1.y , R2.y)) return false;
	if(p1.z < _min(R1.z , R2.z)) return false;
	if(p1.z > _max(R1.z , R2.z)) return false;
	return true;
}

double distsq(const point &p1, const point &p2) {
	return sq(p1.x - p2.x) + sq(p1.y - p2.y) + sq(p1.z - p2.z);
}

bool outsideCircle(const point &p) {
	int i;
	for(i = 0; i < SZ(vp); i++) {
		if(distsq(vp[i].ff, p) > sq(vp[i].ss)) continue;
		else return false;
	}
	return true;
}

double getMinRad(const point &p) {
	int i;
	double res = 1e19;
	for(i = 0; i < SZ(vp); i++) {
		double dd = sqrt(distsq(vp[i].ff, p)) - vp[i].ss;
		res = _min(res, dd);
	}
	return res;
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	double PI = acos(-1.0), area, ans, rarea;
	int cs = 1, i;
	while(scanf("%d", &n) == 1 && n) {
		cin >> R1.x >> R1.y >> R1.z;
		cin >> R2.x >> R2.y >> R2.z;
		for(i = 0; i < n; i++) {
			idx[i] = i;
			scanf("%lf %lf %lf", &p[i].x, &p[i].y, &p[i].z);
		}
		ans = 0;
		do {
			area = 0.0;
			vp.clear();
			for(i = 0; i < n; i++) {
				//printf("%d ", idx[i]);
				point p1 = p[idx[i]];
				if(insideRect(p1) && outsideCircle(p1)) {
					double tempRad = fabs(R1.x - p1.x);
					tempRad = _min(tempRad, fabs(R1.y - p1.y));
					tempRad = _min(tempRad, fabs(R1.z - p1.z));
					tempRad = _min(tempRad, fabs(R2.x - p1.x));
					tempRad = _min(tempRad, fabs(R2.y - p1.y));
					tempRad = _min(tempRad, fabs(R2.z - p1.z));
					tempRad = _min(tempRad, getMinRad(p1));
					vp.PB(MP(p1, tempRad));
					area += 4.0 / 3.0 * PI * tempRad * sq(tempRad);
				}
			}
			//printf("\n");
			ans = _max(ans, area);
		} while(next_permutation(idx, idx + n));
		rarea = fabs(R1.x - R2.x) * fabs(R1.y - R2.y) * fabs(R1.z - R2.z);
		printf("Box %d: %.0lf\n\n", cs++, rarea - ans + EPS);
	}
	return 0;
}
