#include <stdio.h>
#include <vector>
#include <cmath>

using namespace std;

int magnify(int m, int x)
{
	if(m >= 1)
	{
		int power = pow(5,m-1);
		int x2 = x/power;

		if(x2 == 0 || x2 == 4)
		{
			return 0;
		}
		else if(x2 == 1 || x2 == 3)
		{
			return 1*power + magnify(m-1,x%power);
		}
		else if(x2 == 2)
		{
			return 2*power + magnify(m-1,x%power);
		}
	}
	return 0;
}

int main(int argc, char *argv[])
{
	//Read the number of tests
	int T  = 0;
	scanf("%d",&T);

	for(int i = 0; i < T; ++i)
	{
		//Read the magnification level
		int m = 0;
		scanf("%d",&m);
		

		//Read the x cooridinate
		int x = 0;
		scanf("%d",&x);

		//Read the y coordinate
		int y = 0;
		scanf("%d",&y);

		if(y < magnify(m,x))
		{
			printf("crystal\n");
		}
		else
		{
			printf("empty\n");
		}

 
	}

	return 0;
}
