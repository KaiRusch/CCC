#include <stdio.h>

int main(int argc, char *argv[])
{	
	//Read the number player who scored the goal
	int player = 0;
	scanf("%d",&player);

	//Use nCr to calculate the number of combinations
	int c = 0;

	c = ((player-1)*(player-2)*(player-3))/(6);
	
	//Print the number of possible combinations
	printf("%d\n",c);

	return 0;
}



