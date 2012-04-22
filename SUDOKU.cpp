/*
USER: zobayer
TASK: SUDOKU
ALGO: dancing links algorithm-x
*/

#include <stdio.h>

/*
dz = length of smaller cells
dz2 = dz^2, dz4 = dz^4, rows = dz2 * dz4, cols = 4 * dz4
dlxcells = rows * 4 + cols
*/

#define dz 4
#define dz2 16
#define dz4 256
#define rows 4096
#define cols 1024
#define dlxcells 17408

#define REMOVEH(x) L[R[x]]=L[x];R[L[x]]=R[x]
#define INSERTH(x) L[R[x]]=x;R[L[x]]=x
#define REMOVEV(x) U[D[x]]=U[x];D[U[x]]=D[x]
#define INSERTV(x) U[D[x]]=x;D[U[x]]=x

int L[dlxcells], R[dlxcells], U[dlxcells], D[dlxcells], C[dlxcells];
int S[cols], N[cols], DLXmin[rows], solution[dz4], sol[dz4], cellmax, colmax;
static char sudoku[16][18], ibuff[3000], obuff[3000], dump[4], test, found;
static char *in = ibuff, *out = obuff;

inline void getstr(char *str) {
	while(*in>13) *str++ = *in++;
	*str = 0, in++;
}

inline void insertR(int item, int pos) {
	L[item] = pos;
	R[item] = R[pos];
	L[R[item]] = item;
	R[L[item]] = item;
}

inline void insertD(int item, int pos) {
	U[item] = pos;
	D[item] = D[pos];
	U[D[item]] = item;
	D[U[item]] = item;
	C[item] = C[pos];
	S[C[item]]++;
}

inline void insertC(int i, int j, int v) {
	v--;
	L[cellmax] = cellmax, R[cellmax] = cellmax;
	insertR(cellmax + 1, cellmax);
	insertR(cellmax + 2, cellmax + 1);
	insertR(cellmax + 3, cellmax + 2);
	insertD(cellmax, i * dz2 + j + 1);
	insertD(cellmax + 1, i * dz2 + v + dz4 + 1);
	insertD(cellmax + 2, j * dz2 + v + dz4*2 + 1);
	insertD(cellmax + 3, (i/dz*dz+j/dz)*dz2 + v + dz4 * 3 + 1);
	cellmax += 4;
}

inline void init() {
	
	L[0] = R[0] = 0;
	for(int i = 1; i <= 4 * dz4; i++) {
		insertR(i, i-1);
		S[i] = 0, U[i] = D[i] = C[i] = i;
	}
	colmax = cellmax = dz4 * 4 + 1;
	found = 0;
}

inline void readSudoku() {
	int i, j, v;
	for(i = 0; i < dz2; i++) {
		getstr(sudoku[i]);
		for(j = 0; j < dz2; j++) {
			v = sudoku[i][j] - 'A' + 1;
			if(sudoku[i][j]=='-') v = -1;
			if(v == -1) for(v = 0; v < dz2; v++) insertC(i, j, v + 1);
			else insertC(i, j, v);
		}
	}
}

inline void coverCol(int col) {
	int i, j;
	REMOVEH(C[col]);
	for(i = D[C[col]]; i != C[col]; i = D[i]) {
		for(j = R[i]; j != i; j = R[j]) {
			REMOVEV(j);
			S[C[j]]--;
		}
	}
}

inline void uncoverCol(int col) {
	int i, j;
	for(i = U[C[col]]; i != C[col]; i = U[i]) {
		for(j = L[i]; j != i; j = L[j]) {
			S[C[j]]++;
			INSERTV(j);
		}
	}
	INSERTH(C[col]);
}

inline void DLXsolution() {
	int i, j, s, c, ii;
	for(i = 0; i < dz4; i++) sol[i] = 0;
	for(i = 0; i < dz4; i++) {
		s = solution[i];
		c = C[s];
		if(c > dz4) c = C[R[s]];
		if(c > dz4) c = C[R[R[s]]];
		if(c > dz4) c = C[R[R[R[s]]]];
		ii = c-1;
		c = C[s];
		if(c <= dz4 || c > dz4*2) c = C[R[s]];
		if(c <= dz4 || c > dz4*2) c = C[R[R[s]]];
		if(c <= dz4 || c > dz4*2) c = C[R[R[R[s]]]];
		sol[ii] = (c-1) % dz2 + 1;
	}
	for(i = 0; i < dz2; i++) {
		for(j = 0; j < dz2; j++) *out++ = (sol[i*dz2 + j]+'A'-1);
		*out++ = '\n';
	}
}

void solveDLX(int k) {
	int i, j, r, c, mini, mins, col;
	if(!R[0]) {
		DLXsolution();
		found = 1;
		return;
	}
	mini = R[0];
	mins = S[R[0]];
	for(i = R[R[0]]; i != 0; i = R[i]) {
		if(S[i] < mins) {
			mins = S[i];
			mini = i;
		}
	}
	col = mini;
	if(mins == 0) return;
	coverCol(col);
	for(r = D[col]; r != col; r = D[r]) {
		solution[k] = r;
		for(c = R[r]; c != r; c = R[c]) {
			coverCol(c);
		}
		solveDLX(k + 1);
		if(found) return;
		c = C[r];
		for(j = L[r]; j != r; j = L[j]) {
			uncoverCol(j);
		}
	}
	uncoverCol(col);
}

int main() {
	fread_unlocked(ibuff, 3000, 1, stdin);
	getstr(dump);
	test = atoi(dump);
	while(test--) {
		init();
		readSudoku();
		solveDLX(0);
		if(test) getstr(dump), *out++ = '\n';
	}
	fwrite_unlocked(obuff, out - obuff, 1, stdout);
	return 0;
}
