/*
USER: zobayer
TASK: GCD3
ALGO: math
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <ios>
#include <cstring>
using namespace std;

int main()
{
	char num1[300], num2[300];
	int k, t, len, i;
	long long pow2[17], temp;
	pow2[0] = 1;
	for(i=1; i<17; i++)
		pow2[i] = pow2[i-1] << 1;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%s %s %d", num1, num2, &k);
		len = strlen(num1);
		if((num1[len-1]-'0')&1) printf("1\n");
		else
		{
			i = (len<k)?len:k;
			sscanf(&num1[len-i], "%lld", &temp);
			for( ; i>0; i--)
			{
				if(!(temp&(pow2[i]-1)))
				{
					printf("%lld\n", pow2[i]);
					break;
				}
			}
		}
	}
	return 0;
}
