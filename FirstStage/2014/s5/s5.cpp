#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N = 0;
	cin >> N;

	vector<int> origin(2,0);
	vector<vector<int> > points(1,origin);

	for(int i = 0; i < N; ++i)
	{
		int x = 0;
		cin >> x;
		int y = 0;
		cin >> y;

		vector<int> point(2,0);
		point[0] = x;
		point[1] = y;

		points.push_back(point);

	}

	vector<vector<int> > pairs;

	for(int i = 0; i <=N; ++i)
	{
		for(int j = i+1; j <= N; ++j)
		{
			int dx = points[i][0] - points[j][0];
			int dy = points[i][1] - points[j][1];

			int distance = dx*dx + dy*dy;

			vector<int> pair(3,0);
			pair[0] = distance;
			pair[1] = i;
			pair[2] = j;

			pairs.push_back(pair);

		}
	}

	sort(pairs.begin(),pairs.end());

	vector<int> pDist(N+1,0);
	vector<int> pBest(N+1,0);
	vector<int> best(N+1,0);

	for(int i = 0; i < pairs.size(); ++i)
	{
		int d = pairs[i][0];
		int a = pairs[i][1];
		int b = pairs[i][2];

		if(d!=pDist[a])
		{
			pDist[a] = d;
			pBest[a] = best[a];
		}
		if(d!=pDist[b])
		{
			pDist[b] = d;
			pBest[b] = best[b];
		}

		if(a == 0)
		{
			if(best[b] + 1 > best[a])
			{
				best[a] = best[b] + 1;
			}
		}
		else
		{
			if(pBest[b] + 1 > best[a])
			{
				best[a] = pBest[b] + 1;
			}
			if(pBest[a] + 1 > best[b])
			{
				best[b] = pBest[a] + 1;
			}
		}
	}

	cout << best[0] << endl;

	return 0;
}
