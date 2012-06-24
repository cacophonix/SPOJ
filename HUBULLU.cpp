/*
USER: zobayer
TASK: HUBULLU
ALGO: ad-hoc
*/

#include <ios>
using namespace std;

int main()
{
	int n, f, t;
	char player[2][20] = {"Airborne wins.", "Pagfloyd wins."};
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &f);
		puts(player[f]);
	}
	return 0;
}
