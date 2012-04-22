/*
USER: zobayer
TASK: MUL
ALGO: karatsuba multiplication
*/

#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

void bignum_read(int *dig, int &digs) {
	int decimal, decimals, idx, jdx, mult, div, carry, temp;
	while(!isdigit(decimal=getchar()));
	decimals = 9, idx = -1;
	do {
		if(decimals==9) {
			dig[++idx] = 0;
			decimals = 0;
		}
		dig[idx] = 10*dig[idx] + decimal - '0';
		decimals++;
	} while(isdigit(decimal=getchar()));
	digs = idx + 1;
	for(jdx=0; jdx<idx; jdx++, idx--) swap(dig[idx], dig[jdx]);
	if(digs>0 && decimals!=9) {
		mult = 1, div = 1000000000, carry = 0;
		while(decimals--) {
			mult *= 10;
			div /= 10;
		}
		for(idx=digs-1; idx>0; idx--) {
			temp = dig[idx] % div;
			dig[idx] = mult*carry + dig[idx]/div;
			carry = temp;
		}
		dig[0] += mult*carry;
	}
	if(digs==1 && dig[0]==0) digs = 0;
}

void bignum_write(int *dig, int digs) {
	int idx, div, print, decimal;
	if(digs==0) {
		putchar('0');
		return;
	}
	div = 100000000, print = 0;
	while(div) {
		decimal = (dig[digs-1]/div)%10;
		if(print || decimal) {
			putchar(decimal + '0');
			print = 1;
		}
		div /= 10;
	}
	for(idx=digs-2; idx>=0; idx--) {
		div = 100000000;
		while(div) {
			decimal = (dig[idx]/div) % 10;
			putchar(decimal + '0');
			div /= 10;
		}
	}
}

void bignum_copy(int *tdig, int &tdigs, int *sdig, int sdigs) {
	memmove(tdig, sdig, sizeof(int) * sdigs);
	tdigs = sdigs;
}

void bignum_addto(int *tdig, int &tdigs, int *sdig, int sdigs) {
	int sidx, tidx, carry = 0;
	for(tidx=sidx=0; tidx<tdigs || sidx<sdigs; tidx++, sidx++) {
		if(tidx < tdigs) carry += tdig[tidx];
		if(sidx < sdigs) carry += sdig[sidx];
		if(carry >= 1000000000) tdig[tidx] = carry-1000000000, carry=1;
		else tdig[tidx] = carry, carry = 0;
	}
	if(carry) tdig[tidx++] = carry;
	tdigs = tidx;
}

void bignum_subfrom(int *tdig, int &tdigs, int *sdig, int sdigs) {
	int tidx, sidx, carry = 0;
	for(tidx=sidx=0; tidx<tdigs; tidx++, sidx++) {
		carry += tdig[tidx];
		if(sidx < sdigs) carry -= sdig[sidx];
		if(carry < 0) tdig[tidx]=carry+1000000000, carry=-1;
		else tdig[tidx] = carry, carry = 0;
	}
	while(tidx > 0 && tdig[tidx-1]==0) tidx--;
	tdigs = tidx;
}

void bignum_intmul(int *tdig, int &tdigs, int *sdig, int sdigs, int n) {
	int idx, carry = 0;
	long long temp;
	for(idx=0; idx<sdigs; idx++) {
		/*
		temp = (long long)(n * sdig[idx] + carry);
		carry = (int)(temp / 1000000000LL);
		tdig[idx] = (int)(temp % 1000000000LL);
		*/
		__asm__ __volatile__(
			"mull	%%edx				\n\t"
			"addl	%%ebx,%%eax			\n\t"
			"adcl	$0,%%edx			\n\t"
			"movl	$1000000000,%%ebx	\n\t"
			"divl	%%ebx				\n\t"
			: "=a" (carry), "=d" (tdig[idx])
			: "a" (n), "b" (carry), "d" (sdig[idx])
		);
	}
	if(carry) tdig[idx++] = carry;
	tdigs = idx;
}

#define KARATSUBA_LIMIT 20
void karatsuba_mul(int *pdig, int &pdigs, int *adig, int adigs, int *bdig, int bdigs);

void bignum_mul(int *pdig, int &pdigs, int *adig, int adigs, int *bdig, int bdigs) {
	int *tempdig, tempdigs, aidx;
	if(adigs==0 || bdigs==0) {
		pdigs = 0;
		return;
	}
	if(adigs > bdigs) {
		bignum_mul(pdig, pdigs, bdig, bdigs, adig, adigs);
		return;
	}
	if(adigs >= KARATSUBA_LIMIT && bdigs >= KARATSUBA_LIMIT) {
		karatsuba_mul(pdig, pdigs, adig, adigs, bdig, bdigs);
		return;
	}
	tempdig = (int *)malloc(sizeof(int)*(bdigs + 1));
	pdigs = 0;
	for(aidx=0; aidx < adigs; aidx++) {
		bignum_intmul(tempdig, tempdigs, bdig, bdigs, adig[aidx]);
		pdigs -= aidx;
		bignum_addto(&pdig[aidx], pdigs, tempdig, tempdigs);
		pdigs += aidx;
	}
	free(tempdig);
}

void karatsuba_mul(int *pdig, int &pdigs, int *adig, int adigs, int *bdig, int bdigs) {
	int *a0dig, a0digs, *a1dig, a1digs;
	int *b0dig, b0digs, *b1dig, b1digs;
	int *t0dig, t0digs, *t1dig, t1digs;
	a0digs = b0digs = (bdigs+1)/2;
	a1digs = adigs - a0digs;
	b1digs = bdigs - b0digs;
	a0dig = adig;
	if(a1digs >= 0) a1dig = adig + a0digs;
	else a1dig = NULL, a1digs = 0, a0digs = adigs;
	b0dig = bdig;
	b1dig = bdig + b0digs;
	t0dig = (int *)malloc(sizeof(int)*(bdigs+2));
	t0digs = 0;
	t1dig = (int *)malloc(sizeof(int)*(bdigs+2));
	t1digs = 0;
	pdigs = 0;
	bignum_copy(t1dig, t1digs, a0dig, a0digs);
	bignum_addto(t1dig, t1digs, a1dig, a1digs);
	bignum_copy(pdig, pdigs, b0dig, b0digs);
	bignum_addto(pdig, pdigs, b1dig, b1digs);
	bignum_mul(t0dig, t0digs, t1dig, t1digs, pdig, pdigs);
	bignum_mul(pdig, pdigs, a0dig, a0digs, b0dig, b0digs);
	bignum_mul(t1dig, t1digs, a1dig, a1digs, b1dig, b1digs);
	bignum_subfrom(t0dig, t0digs, pdig, pdigs);
	bignum_subfrom(t0dig, t0digs, t1dig, t1digs);
	pdigs -= b0digs;
	pdig += b0digs;
	bignum_addto(pdig, pdigs, t0dig, t0digs);
	pdigs -= b0digs;
	pdig += b0digs;
	bignum_addto(pdig, pdigs, t1dig, t1digs);
	pdigs += 2*b0digs;
	free(t1dig);
	free(t0dig);
}

int main() {
	static int adig[50000], bdig[50000], pdig[100000];
	int adigs, bdigs, pdigs, cs;
	scanf("%d", &cs);
	while(cs--) {
		bignum_read(adig, adigs);
		bignum_read(bdig, bdigs);
		bignum_mul(pdig, pdigs, adig, adigs, bdig, bdigs);
		bignum_write(pdig, pdigs);
		putchar('\n');
	}
	return 0;
}
