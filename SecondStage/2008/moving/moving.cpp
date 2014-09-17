#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool impossible = false;

void top_sort(vector<vector<int> > &ancestors, int vertex, int *adjMat, bool *visited, bool *queue, vector<int> &topList)
{
	if(!visited[vertex])
	{
		if(adjMat[vertex] != 0)
		{
			for(int i = 0; i < ancestors[vertex].size(); ++i)
			{
				if(ancestors[vertex][i] == adjMat[vertex])
				{
					impossible = true;
					return;
				}
			}

			ancestors[adjMat[vertex]] = ancestors[vertex];
			ancestors[adjMat[vertex]].push_back(vertex);

			top_sort(ancestors, adjMat[vertex], adjMat, visited, queue, topList);
			adjMat[vertex];
		}

		topList.push_back(vertex);
		visited[vertex] = true;
		queue[vertex] = false;
	}

}

int main()
{
	int n = 0;
	cin >> n;

	int adjMat[101] = {0};
	string names[101] = {"\0"};
	bool visited[101] = {false};

	vector<int> topList;
	bool queue[101] = {false};

	for(int i = 0; i < n; ++i)
	{
		string name;
		cin >> name;

		int address1;
		cin >> address1;

		int address2;
		cin >> address2;

		adjMat[address1] = address2;
		names[address1] = name;

		queue[address1] = true;
	}

	vector<int> empty;
	vector<vector<int> > ancestors(101,empty);
	
	int i = 1;
	while(i <= 100)
	{
		if(queue[i])
		{
			top_sort(ancestors, i,adjMat,visited,queue,topList);
		}
		++i;
	}

	if(!impossible)
	{
		for(int i = 0; i < topList.size(); ++i)
		{
			if(names[topList[i]] != "\0")
			{
				cout << names[topList[i]] << endl;
			}
		}
	}

	else
	{
		cout << "Impossible\n";
	}

	return 0;
}
