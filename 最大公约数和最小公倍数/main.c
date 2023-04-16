#include <stdio.h>

int getLCM(int n1, int n2)
{
	int num = (n1 > n2)?(n2):(n1);
	for (; num > 0; num--)
	{
		if(n1 % num == 0 && n2 % num == 0)
		{
			break;
		}
	}

	return num;
}

int getGCD(int n1, int n2, int LCM)
{
	return n1 * n2 / LCM;
}

int main(int argc, char **argv)
{
	int n1,n2,n3,n4;
	scanf("%d %d", &n1, &n2);
	scanf("%d %d", &n3, &n4);
	
	int LCM1 = getLCM(n1, n2);
	int LCM2 = getLCM(n3, n4);
	printf("%d\n", LCM1 + LCM2);
	printf("%d", getGCD(n1, n2, LCM1) + getGCD(n3, n4, LCM2));
	return 0;
}