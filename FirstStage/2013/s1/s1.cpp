#include <stdio.h>

bool distinct(int year)
{
	//Convert the year to a c string
	char yStr[5];
	sprintf(yStr,"%d",year);

	for(int i = 0; i <= 3; ++i)
	{
		for (int j = i+1; j <= 4; ++j)
		{
			if(yStr[i] == yStr[j])
			{
				return false;
			}
		}
	}
	return true;
}

int main(int argc, char *argv[])
{	
	//Read the year
	int year = 0;
	scanf("%d",&year);

	year++;

	while(!distinct(year))
	{
		year++;
	}

	printf("%d\n",year);

	return 0;
}
