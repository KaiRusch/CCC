#include <stdio.h>
#include <string>

using namespace std;

//The favorite team
int T = 0;

//The number of times the favorite team wins the tourney
int favWins = 0;

//Array showing the games and which teams playes in them
int games[6][2] = {{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}};

void recurse(int G, string result)
{
	//If the tournament is over
	if(G == 6)
	{
		//Award points to the teams
		int points[4] = {0};
		for(int i = 0; i < 6; ++i)
		{
			if(result[i] == 'W')
			{
				points[games[i][0]-1]+=3;
			}
			else if(result[i] == 'L')
			{
				points[games[i][1]-1]+=3;
			}
			else
			{
				points[games[i][0]-1]++;
				points[games[i][1]-1]++;
			}
		}

		//Check if the favorite team has the most points
		int i = 0;
		bool won = true;
		while(i < 4)
		{
			if(i != T-1)
			{
				if(points[i] >= points[T-1])
				{
					won = false;
				}
			}
			i++;
		}

		if(won)
		{
			favWins++;
		}
	}

	else
	{
		int i = 0;
		while(result[i] != '-')
		{
			i++;
		}

		result[i] = 'W';
		recurse(G+1,result);

		result[i] = 'L';
		recurse(G+1,result);

		result[i] = 'T';
		recurse(G+1,result);
	}
}

int main(int argc, char *argv[])
{
	//Read favorite team
	scanf("%d",&T);

	//Read the number of games already played
	int G = 0;
	scanf("%d",&G);



	//Shows if games was T (tie), W (win) or L (loss)
	string result = "------";

	for(int i = 0; i < G; ++i)
	{
		//Read team A and B
		int A = 0;
		int B = 0;
		scanf("%d %d",&A,&B);
		
		//Read score A and B
		int sA = 0;
		int sB = 0;
		scanf("%d %d",&sA,&sB);

		//Increment J until the game mathces a game in the games array
		int j = 0;
		while(games[j][0] != A || games[j][1] != B)
		{
			j++;
		}

		if(sA > sB)
		{
			result[j] = 'W';
		}
		else if(sB > sA)
		{
			result[j] = 'L';
		}
		else
		{
			result[j] = 'T';
		}
	}

	recurse(G,result);

	printf("%d\n",favWins);

	return 0;
}
