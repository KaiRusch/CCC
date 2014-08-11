#include <stdio.h>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	//The number of guests
	int K = 0;
	scanf("%d",&K);

	//A vector containing the number of guests
	vector<int> guests;
	
	for(int i = 0; i < K; ++i)
	{
		guests.push_back(i+1);
	}


	//The number of elimination rounds
	int m = 0;
	scanf("%d",&m);

	for(int i = 0; i < m; ++i)
	{	
		int r = 0;
		scanf("%d",&r);

		vector<int> newGuests;
		for(int j = 0; j < guests.size(); ++j)
		{
			if((j+1)%r != 0)
			{
				newGuests.push_back(guests[j]);
			}
		}

		guests = newGuests;
	}

	for(int i = 0; i < guests.size(); ++i)
	{
		printf("%d\n",guests[i]);
	}

	return 0;
}
