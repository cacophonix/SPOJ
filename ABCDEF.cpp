/*
USER: zobayer
TASK: ABCDEF
ALGO: binary search
*/

#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 101

int v[2000000];

int main() {
	int n, a[MAX];
	int i, j, k, cnt, p, val;
	scanf("%d", &n);
	cnt = p = 0;
	for(i=0; i < n; i++) scanf("%d",&a[i]);
	for(i=0; i<n; i++) if( a[i] )
		for(j=0 ; j<n; j++)
			for(k=0 ; k<n; k++)
				v[p++] = a[i]*(a[j]+a[k]);
	sort(v, v+p);
	for(i=0 ; i<n; i++) {
		for(j=0 ; j<n; j++) {
			for(k=0 ; k<n; k++) {
				val = a[i]*a[j]+a[k];
				cnt += upper_bound( v, v+p, val) - lower_bound( v, v+p, val );
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}
