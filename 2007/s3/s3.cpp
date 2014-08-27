#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	vector<int> friends(100000,0);

	bool quit = false;
	while(!quit)
	{
		int x = 0;
		cin >> x;
		int y = 0;
		cin >> y;

		if(x == 0 && y == 0)
		{
			quit = true;
		}	
		else
		{
			if(friends[x] == 0)
			{
				friends[x] = y;
			}
			else
			{
				int d = 0;
				int student = x;
				while(friends[student] != y && friends[student] != 0 && friends[student] != x)
				{
					student = friends[student];
					d++;
				}
				if(friends[student] == 0 || friends[student] == x)
				{
					cout << "No\n";
				}
				else
				{
					cout << "Yes " << d << endl;
				}
			}
		}
	}	

	return 0;
}
