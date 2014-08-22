#include <iostream>
#include <vector>

using namespace std;

const int infinity = 1000;

int main()
{
	//Read the number of lights
	int K = 0;
	cin >> K;

	//Vector containing the configuration of lights
	vector<int> lights;

	//Read the configuration of lights
	for(int i = 0; i < K; ++i)
	{
		int light = 0;
		cin >> light;
		lights.push_back(light);
	}

	//Vector containing groups of on lights [0] = left [1] = right
	vector<vector<int> > groups;
	//An empty group [0,0]
	vector<int> empty(2,0);
	groups.push_back(empty);
	
	//Index of last group
	int G = 0;

	//Group the lights
	for(int i = 0; i < K; ++i)
	{
		//If the lights are on
		if(lights[i] == 1)
		{
			//If the group is empty
			if(groups[G][1] == 0)
			{
				//Set left to i
				groups[G][0] = i;
				//Set right to i
				groups[G][1] = i;
			}
			//Increment right bound
			groups[G][1]++;
		}
		//Light is off and group is not empty
		else if(groups[G][1] != 0)
		{
			//Place empty group
			groups.push_back(empty);
			G++;
		}
	}

	//If last group is empty
	if(groups[G][1] == 0)
	{
		//Remove it
		groups.pop_back();
		G--;
	}

	//Vector containing the minimum number of moves to turn each group + groups to its right off
	vector<int> minMoves(G+1,infinity);
	minMoves.push_back(0);

	//Calculate the minimum number of moves for each group starting at the right
	for(int i = G; i >= 0; i--)
	{
		int j = i;
		while(j <= G && groups[j][1] - groups[i][0] <= 7)
		{
			//The span of the two groups
			int span = groups[j][1] - groups[i][0];
			//The number of lights which are on
			int on = (groups[j][1] - groups[j][0])+(groups[i][1] - groups[i][0]);
			if(i == j)
			{
				on = span;
			}
			
			if(span <= 5)
			{
				if(span < 4)
				{
					span = 4;
				}

				int minMove = span - on;
				if(minMove + minMoves[j+1] < minMoves[i])
				{
					minMoves[i] = minMove + minMoves[j+1];
				}
			}

			else if(span <= 7)
			{
				if(span == 7 && lights[i+3] == 0)
				{
					int minMove = span - on;
					if(minMove + minMoves[j+1] < minMoves[i])
					{
						minMoves[i] = minMove + minMoves[j+1];
					}
				}
				else if(span ==6 && (lights[i+3] == 0 || lights[i+2] == 0))
				{
					int minMove = span - on;
					if(minMove + minMoves[j+1] < minMoves[i])
					{
						minMoves[i] = minMove + minMoves[j+1];
					}
				}
			}
		
			j++;
		}
	}

	//Print solution at minMoves[0]
	cout << minMoves[0] << endl;

	return 0;
}
