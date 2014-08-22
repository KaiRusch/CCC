#include <iostream>
#include <vector>

using namespace std;

bool search(vector<vector<int> > &graph, int N, int p, int q)
{
	vector<int> queue(1,p);
	vector<bool> visited(N+1,false);

	while(queue.size() > 0)
	{
		visited[queue[0]] = true;
		for(int i = 0; i <= N; ++i)
		{
			if(i == q && graph[queue[0]][i])
			{
				return true;
			}
			else
			{
				if(!visited[i] && graph[queue[0]][i] == 1)
				{
					queue.push_back(i);
				}
			}
		}
		queue.erase(queue.begin());
	}

	return false;
	
}

int main()
{
	int N = 0;
	cin >> N;
	int M = 0;
	cin >> M;

	vector<int> temp(N+1,0);
	vector<vector<int> > graph(N+1,temp);

	for(int i = 0; i < M; ++i)
	{
		int x = 0;
		cin >> x;
		int y = 0;
		cin >> y;

		graph[x][y] = 1;
	}

	int p = 0;
	cin >> p;
	int q = 0;
	cin >> q;

	if(search(graph,N,p,q))
	{
		cout << "yes\n";
	}
	else if(search(graph,N,q,p))
	{
		cout << "no\n";
	}
	else
	{
		cout << "unknown\n";
	}

	return 0;
}
