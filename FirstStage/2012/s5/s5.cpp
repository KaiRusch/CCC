#include <iostream>
#include <vector>

using namespace std;

int cat = 1000000000;

int main()
{
	int R  = 0;
	cin >> R;
	int C = 0;
	cin >> C;

	vector<int> column(R+1,0);
	vector<vector<int> > grid(C+1,column);

	grid[1][1] = 1;

	int K = 0;
	cin >> K;

	for(int i = 0; i < K; ++i)
	{
		int y = 0;
		cin>>y;
		int x = 0;
		cin >> x;

		grid[x][y] = cat;
	}

	for(int i = 1; i <= R; ++i)
	{
		for(int j = 1; j <= C; ++j)
		{
			if((i != 1 || j != 1) && (grid[j][i] != cat))
			{
				int up = 0;
				int left = 0;
				if(grid[j-1][i] != cat)
				{
					left = grid[j-1][i];
				}
				if(grid[j][i-1] != cat)
				{
					up = grid[j][i-1];
				}

				grid[j][i] = up + left;

			}
		}

	}

	cout << grid[C][R] << endl;

	return 0;
}
