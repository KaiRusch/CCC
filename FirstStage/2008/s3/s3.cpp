#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t = 0;
	cin >> t;

	for(int i = 0; i < t; ++i)
	{
		int r = 0;
		cin >> r;
		int c = 0;
		cin >> c;

		int adjMat[441][441] = {0};

		vector<char> intersections(1,'+');

		for(int k = 0; k < r; ++k)
		{
			for(int l = 1; l <= c; ++l)
			{
				char intersection = ' ';
			       	cin >> intersection;
				intersections.push_back(intersection);
				

				//Connect it to intersection to the west
				if(l > 1 && (intersection == '+' || intersection == '-'))
					adjMat[k*c + l][k*c + l - 1] = 1;
				//Connect it to intersection to the east
				if(l < c && (intersection == '+' || intersection == '-'))
				        adjMat[k*c + l][k*c + l + 1] = 1;
				//Connect it to intersection to the north	
				if(k > 0 && (intersection == '+' || intersection == '|'))
					adjMat[k*c + l][(k-1)*c + l] = 1;
				//Connect it to insersection to the south
				if(k < r && (intersection == '+' || intersection == '|'))
					adjMat[k*c + l][(k+1)*c + l] = 1;
				
			}
		}

		vector<int> frontier(1,1);
		int levels[441] = {0};
		levels[1] = 1;

		while(frontier.size() > 0)
		{
			vector<int> next;

			for(int x = 0; x  < frontier.size(); ++x)
			{
				int currentVertex = frontier[x];
				for(int y = 1; y <= r*c; ++y)
				{
					if(adjMat[currentVertex][y] == 1 && levels[y] == 0)
					{
						next.push_back(y);
						levels[y] = levels[currentVertex] + 1;
					}
				}
			}

			frontier = next;
		}

		if(levels[r*c] == 0 || intersections[r*c] == '*')
		{
			cout << -1 << endl;
		}
		else
		{
			cout << levels[r*c] << endl;
		}
	}
	return 0;
}
