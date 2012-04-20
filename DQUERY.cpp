/*
USER: zobayer
TASK: DQUERY
ALGO: binary indexed tree
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int order, from, to;
} t_query;

int queries, numbers, number[333333];
t_query query[222222];

int compare_to(const void *ptr1, const void *ptr2) {
	t_query *q1 = (t_query *)ptr1;
	t_query *q2 = (t_query *)ptr2;
	return q1->to - q2->to;
}

int norm, present[1<<20], lastoccur[1111111];

void init_present() {
	for(norm = 1; norm < numbers; norm *= 2);
}

void add_present(int idx) {
	for(int i=norm+idx; i; i /= 2) present[i]++;
}

void remove_present(int idx) {
	for(int i=norm + idx; i; i /= 2) present[i]--;
}

int count_before(int idx) {
	int result = 0, root = 1, size = norm;
	if(idx >= size) return present[1];
	while(true) {
		if(idx==0) return result;
		if(idx < size / 2) root = 2*root;
		else if(idx ==size / 2) return result + present[2*root];
		else {
			result += present[2*root];
			idx -= size / 2;
			root = 2 * root + 1;
		}
		size /= 2;
	}
}

void read_input() {
	int i, f, t;
	scanf("%d", &numbers);
	for(i = 0; i < numbers; i++) scanf("%d", &number[i]);
	scanf("%d", &queries);
	for(i = 0; i < queries; i++) {
		scanf("%d%d", &f, &t);
		query[i] = (t_query){i, f-1, t-1};
	}
}

int answer[222222];

int main() {
	int n, q;
	read_input();
	qsort(query, queries, sizeof(t_query), compare_to);
	init_present();
	n = -1;
	for(q = 0; q < queries; q++) {
		while(n < query[q].to) {
			n++;
			if(lastoccur[number[n]]) remove_present(lastoccur[number[n]]-1);
			add_present(n);
			lastoccur[number[n]] = n + 1;
		}
		answer[query[q].order] = present[1] - count_before(query[q].from);
	}
	for(q = 0; q < queries; q++) printf("%d\n", answer[q]);
	return 0;
}
