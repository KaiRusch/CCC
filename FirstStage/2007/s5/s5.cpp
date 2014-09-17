#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t = 0;
	cin >> t;

	for(int i = 0; i < t; ++i)
	{
		int n = 0;
		cin >> n;

		int k = 0;
		cin >> k;

		int w = 0;
		cin >> w;

		vector<int> pins(n,0);

		for(int j = 0; j < n; ++j)
		{
			int pin = 0;
			cin >> pin;
			pins[j] = pin;
		}

		vector<int> bestScore(n,0);
		bestScore[n-1] = pins[n-1];
		for(int j = 2; j <= w; ++j)
		{
			bestScore[n-j] = pins[n-j] + bestScore[n-j+1];
		}

		vector<int> previousScore(n,0);

		for(int x = 0; x < k; ++x)
		{	
			for(int y = n-w-1; y >= 0; --y)
			{
				int score = 0;
				for(int z = 0; z < w; ++z)
				{
					score+=pins[y+z];
				}

				if(score + previousScore[y+w] > bestScore[y+1])
				{
					bestScore[y] = score + previousScore[y+w];
				}
				else
				{
					bestScore[y] = bestScore[y+1];
				}
			}

			previousScore = bestScore;
		}

		cout << bestScore[0] << endl;
	}	

	return 0;
}
