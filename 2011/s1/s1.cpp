#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	//Read the number of lines to analyze
	int N = 0;
	scanf("%d\n",&N);

	//The number of T characters
	int T = 0;
	//The number of S characters
	int S = 0;

	for(int i = 0; i < N; ++i)
	{	
		//Read the line
		string line;
		getline(cin,line);

		for(int j = 0; j < line.length(); ++j)
		{
			if(line[j] == 't' || line[j] == 'T')
			{
				T++;
			}
			else if(line[j] == 's' || line[j] == 'S')
			{
				S++;
			}
		}
		
	}

	if(T > S)
	{
		printf("English\n");
	}
	else
	{
		printf("French\n");
	}

	return 0;
}
