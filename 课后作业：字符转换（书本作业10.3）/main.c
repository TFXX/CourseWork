#include <stdio.h>
#include <ctype.h>

int main(int argc, char **argv)
{
	FILE *fp = fopen("test.txt", "w");
	if(fp != NULL)
	{
		char c = getchar();
		while(c != '!')
		{
			if(islower(c))
			{
				c = toupper(c);
			}
			fputc(c, fp);
			c = getchar();
		}
		fclose(fp);
	}
	else
	{
		printf("can not open\n");
	}
	return 0;
}