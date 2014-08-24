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
	Path **head = &adjList[x];

	if(*head == NULL)
	{
		*head = new Path(y,c);
	}
	else
	{
		Path *temp = *head;
		*head = new Path(y,c);
		(*head)->next = temp;
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

		if(x >= 1 && x <= N && y >= 1 && y <=N)
		{
	
			insert_path(adjList,x,y,c);
			insert_path(adjList,y,x,c);
		}
	}

	int K = 0;
	cin >> K;

	vector<int> pencilPrices(N+1,0);
	vector<int> pencilShops;

	for(int i = 0; i < K; ++i)
	{
		int z = 0;
		cin >> z;
		int P = 0;
		cin >> P;

		if(z >= 1 && z <= N)
		{
			pencilShops.push_back(z);
			pencilPrices[z] = P;
		}
	}

	int D = 0;
	cin >> D;

	
	vector<int> shortestPath(N+1,INFINITY);
	shortestPath[D] = 0;

	vector<bool> visited(N+1,false);
		
	int city = D;
	Path *current = adjList[city];

	bool visitedAll = false;

	while(!visitedAll)
	{	
		int minPath = INFINITY;
		int minCity = 0;

		for(int j = 1; j <= N; ++j)
		{
			if(shortestPath[j] <= minPath && !visited[j])
			{
				minCity = j;
				minPath = shortestPath[j];
			}
		}

		city = minCity;
		current = adjList[city];		

		while(current != NULL)
		{
			if(current->tradeCost + shortestPath[city] < shortestPath[current->city] && !visited[current->city])
			{
				shortestPath[current->city] = current->tradeCost + shortestPath[city];
			}
				
			current = current->next;
		}

		visited[city] = true;
		
		bool test = true;
		for(int i = 1; i < visited.size(); ++i)
		{
			if(!visited[i])
			{
				test = false;
			}
		}
		if(test)
		{
			visitedAll = true;
		}


	}		


	for(int i = 0; i < pencilShops.size(); ++i)
	{
		int shop = pencilShops[i];
		if(shortestPath[shop] + pencilPrices[shop] < minCost)
		{
			minCost = shortestPath[shop] + pencilPrices[shop];
		}
	}

	cout << minCost << endl;

	return 0;
}

