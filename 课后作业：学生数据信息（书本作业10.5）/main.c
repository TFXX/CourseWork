#include <stdio.h>

struct student
{
	char id[10];
	char name[8];
	int score[3];
	float ave;
}s[5];

int main(int argc, char **argv)
{
	unsigned int i = 0;
	for(; i < 5;  i++)
	{
		scanf("%s %s %d %d %d", s[i].id, s[i].name, s[i].score, s[i].score + 1, s[i].score + 2);
		FILE *fp = fopen("stud.dat", "w");
		if(fp)
		{
			char buffer[128];
			s[i].ave = (double)(s[i].score[0] + s[i].score[1] + s[i].score[2]) / 3; 
			sprintf(buffer, "%s %s %d %d %d %.2f\n", s[i].id, s[i].name, s[i].score[0], s[i].score[1], s[i].score[2], s[i].ave);
			//fputs(buffer, fp);
			fwrite(s + i, sizeof(struct student),1,fp);
			fputs(buffer, stdout);
			fclose(fp);
		}
	}
	
	return 0;
}