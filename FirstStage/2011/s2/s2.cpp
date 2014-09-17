#include <stdio.h>

int main(int argc, char *argv[])
{
	//Read the number of questions
	int N = 0;
	scanf("%d",&N);

	//The number of questions the student got right
	int C = 0;

	//Array of characters containing the answers, and the students answers
	char questions[20000] = {' '};
		
	for(int i = 0; i <= 2*N; ++i)
	{
		char choice = ' ';
		scanf(" %c",&choice);
		questions[i] = choice;
	}

	for(int i = 0; i < N; ++i)
	{
		if(questions[i] == questions[i+N])
		{
			C++;
		}
	}

	printf("%d\n",C);

	return 0;
}
