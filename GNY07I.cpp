/*
USER: zobayer
TASK: GNY07I
ALGO: simulation
*/

#include <cstdio>
#include <cstring>

typedef struct { int f, s; } P;

P cubeAdj[6][6], qAdj[3][4], items[6][4], faces[6];
char adj[8][6][4][6][4];

const int angle[8][3] = {
	{0,1,2}, {0,2,3}, {1,2,5}, {2,3,5},
	{0,1,4}, {0,3,4}, {1,4,5}, {3,4,5}
};

inline void init() {
	cubeAdj[0][1] = (P){3,0}, cubeAdj[1][0] = (P){0,3};
	cubeAdj[0][2] = (P){2,0}, cubeAdj[2][0] = (P){0,2};
	cubeAdj[0][3] = (P){1,0}, cubeAdj[3][0] = (P){0,1};
	cubeAdj[0][4] = (P){0,0}, cubeAdj[4][0] = (P){0,0};
	cubeAdj[1][2] = (P){1,3}, cubeAdj[2][1] = (P){3,1};
	cubeAdj[1][4] = (P){3,1}, cubeAdj[4][1] = (P){1,3};
	cubeAdj[1][5] = (P){2,3}, cubeAdj[5][1] = (P){3,2};
	cubeAdj[2][3] = (P){1,3}, cubeAdj[3][2] = (P){3,1};
	cubeAdj[2][5] = (P){2,0}, cubeAdj[5][2] = (P){0,2};
	cubeAdj[3][4] = (P){1,3}, cubeAdj[4][3] = (P){3,1};
	cubeAdj[3][5] = (P){2,1}, cubeAdj[5][3] = (P){1,2};
	cubeAdj[4][5] = (P){2,2}, cubeAdj[5][4] = (P){2,2};
}

inline bool isadj(int an, const P &a, const P &b) {
	return (adj[an][a.f][a.s][b.f][b.s] == 1);
}

inline bool check() {
	bool a1, a2, a3;
	for(int k = 0; k < 8; k++) {
		a1 = isadj(k,items[0][3],items[1][0]);
		a2 = isadj(k,items[1][3],items[2][0]);
		a3 = isadj(k,items[2][3],items[0][0]);
		if(a1 && a2 && a3) return true;
	}
	return false;
}

int main() {
	int test, cs, i, j, k, nres, a, b;
	char unfold[16], query[8], vres[5];
	P f, p, q;
	init();
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%s", unfold);
		for(i = 0; i < 12; i += 2)
			faces[i >> 1] = (P){unfold[i]-'A', unfold[i+1]-'1'};
		for(i = 0; i < 6; i++)
			for(j = 0; j < 4; j++)
				items[i][(faces[i].s+j)&3] = (P){faces[i].f, j};
		memset(adj, 0, sizeof adj);
		for(k = 0; k < 8; k++) {
			for(i = 0; i < 3; i++) {
				for(j = i+1; j < 3; j++) {
					a = angle[k][i], b = angle[k][j];
					f = cubeAdj[a][b];
					p = items[a][f.f], q = items[b][f.s];
					adj[k][p.f][p.s][q.f][q.s] = 1;
					adj[k][q.f][q.s][p.f][p.s] = 1;
				}
			}
		}
		for(k = nres = 0; k < 5; k++) {
			scanf("%s", query);
			for(i = 0; i < 6; i += 2)
				faces[i >> 1] = (P){query[i]-'A', query[i+1]-'1'};
			for(i = 0; i < 3; i++)
				for(j = 0; j < 4; j++)
					items[i][(faces[i].s+j)&3] = (P){faces[i].f, j};
			vres[k] = check()? 'Y' : 'N';
			nres += (vres[k]=='Y');
		}
		printf("%d %d", cs, nres);
		for(k = 0; k < 5; k++) printf(" %c", vres[k]); printf("\n");
	}
	return 0;
}
