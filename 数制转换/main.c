#include <stdio.h>
#include <string.h>

#define N 128
unsigned int atoi(char c)
{
	if(c <= '9')
	{
		return c - '0';
	}
	else if(c <= 'F')
	{
		return c - 'A' + 10;
	}

	return -1;
}

char itoa(unsigned int i)
{
	if(i >= 10)
	{
		return 'A' + i - 10;
	}
	else
	{
		return '0' + i;
	}
}

int main(int argc, char **argv)
{
	unsigned int a, b ;
	char nums[N];
	scanf("%d %s %d", &a, nums, &b);
	unsigned int length = strlen(nums);

	unsigned int total = 0;
	unsigned int base = 1;

	unsigned int i = 0;
	for(;i < length; i++)
	{
		total += atoi(nums[length - 1 - i]) * base;
		base *= a;
	}

	int stack[N];
	for(i = 0; i < N; i++)
	{
		stack[i] = total % b;
		if(total < b)
		{
			break;
		}
		total /= b;
	}


	for(i++; i > 0; i--)
	{
		printf("%c", itoa(stack[i-1]));
	}
	return 0;
}