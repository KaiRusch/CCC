#include <iostream>
#include <vector>

using namespace std;

const int INFINITY = 1000000;
int minCost = INFINITY;

class Path
{
	public:
		int city;
		int tradeCost;
		Path *next;

		Path(int y, int c) { city = y; tradeCost = c; next = NULL;};
};

void insert_path(vector<Path *> &adjList,int x, int y, int c)
{
	if(adjList[x] == NULL)
	{
		adjList[x] = new Path(y,c);
	}
	else
	{
		Path *temp = adjList[0];
		adjList[x] = new Path(y,c);
		adjList[x]->next = temp;
	}
}

int main()
{
	int N = 0;
	cin >> N;

	vector<Path *> adjList(N+1,NULL);

	int T = 0;
	cin >> T;

	for(int i = 0; i < T; ++i)
	{
		int x = 0;
		cin >> x;
		int y = 0;
		cin >> y;
		int c = 0;
		cin >> c;

		insert_path(adjList,x,y,c);
		insert_path(adjList,y,x,c);
	}

	int K = 0;
	cin >> K;

	vector<int> pencilPrices(K+1,0);
	vector<int> pencilShops;

	for(int i = 0; i < K; ++i)
	{
		int z = 0;
		cin >> z;
		int P = 0;
		cin >> P;
		
		pencilShops.push_back(z);
		pencilPrices[z] = P;
	}

	int D = 0;
	cin >> D;

	for(int i = 0; i < pencilShops.size(); ++i)
	{
		int startCity = pencilShops[i];
		vector<int> shortestPath(N+1,INFINITY);
		shortestPath[startCity] = pencilPrices[startCity];
		
		cout << startCity << endl;

		vector<bool> visited(N+1,false);
		
		int city = startCity;
		Path *current = adjList[city];

		if(current != NULL)
		{
			while(!visited[D])
			{	
				while(current != NULL)
				{
					if(current->tradeCost + shortestPath[city] < shortestPath[current->city] && !visited[current->city])
					{
						cout << "The trade cost from " << city <<  " to " <<  current->city  << " is " << current->tradeCost << " and I have already paid " << shortestPath[city] << endl;
						shortestPath[current->city] = current->tradeCost + shortestPath[city];
					}

					current = current->next;
				}

				visited[city] = true;

				int minPath = INFINITY;
				int minCity = 0;

				for(int j = 1; j <= N; ++j)
				{
					if(shortestPath[j] < minPath && !visited[j])
					{
						minCity = j;
						minPath = shortestPath[j];
					}
				}

				city = minCity;
				current = adjList[city];
			}
			
			cout << shortestPath[D] << endl;
			if(shortestPath[D] < minCost)
			{
				minCost = shortestPath[D];
			}
		}
		
	}

	cout << minCost;

	return 0;
}

