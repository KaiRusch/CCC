#include <iostream>
#include <vector>

using namespace std;

class Edge
{
	public:
		int cost;
		int vertex;

		Edge *next;

		Edge(int c, int v){cost = c; vertex = v; next = NULL;};
};

void insert_edge(Edge **head, int c, int v)
{
	Edge *temp = *head;
	*head = new Edge(c,v);
	(*head)->next = temp;
}

int prim(vector<Edge *> &adjList, int vertexToSkip, int M)
{
	int minCost = 0;

	if(vertexToSkip!=0)
	{
		M++;
	}

	vector<int> verticesInTree (1,1);
	vector<bool> addedVertices (M+1,false);
	addedVertices[1] = true;

	while(verticesInTree.size() < M)
	{
		int minEdgeCost = 5001;
		int minEdgeVertex = 0;

		for(int i = 0; i < verticesInTree.size(); ++i)
		{
			int vertex = verticesInTree[i];
			Edge *current = adjList[vertex];

			while(current != NULL)
			{
				if(current->cost < minEdgeCost && current->vertex != vertexToSkip && !addedVertices[current->vertex])
				{
					minEdgeCost = current->cost;
					minEdgeVertex = current->vertex;
				}
				current = current->next;
			}
		}

		minCost+=minEdgeCost;
		verticesInTree.push_back(minEdgeVertex);
		addedVertices[minEdgeVertex] = true;

	}

	return minCost;
}

int main()
{
	int M = 0;
	cin >> M;

	//0 = corner, 1 = corner, 2 = cost, 3 = pen, 4 = pen
	vector<vector<int> > fences;

	for(int i = 1; i <= M; ++i)
	{
		int e = 0;
		cin >> e;

		vector<int> corners(e,0);

		for(int j = 0; j < e; ++j)
		{
			int corner = 0;
			cin >> corner;
			corners[j] = corner;
		}

		vector<vector<int> > tempFences;

		for(int j = 0; j < e; ++j)
		{
			int cost = 0;
			cin >> cost;

			//0 = corner, 1 = corner, 2 = cost
			vector<int> fence(3,0);

			fence[0] = corners[j];
			fence[2] = cost;

			if(j == e-1)
			{
				fence[1] = corners[0];
			}
			else
			{
				fence[1] = corners[j+1];
			}

			tempFences.push_back(fence);
		}

		for(int j = 0; j < e; ++j)
		{
			bool duplicate = false;
			int k = 0;
			while(!duplicate && k < fences.size())
			{
				if((tempFences[j][0] == fences[k][0] && tempFences[j][1] == fences[k][1])||(tempFences[j][0] == fences[k][1] && tempFences[j][1] == fences[k][0]))
						{
							duplicate = true;
						}
				k++;
			}

			if(duplicate)
			{
				fences[k-1][4] = i;
			}
			else
			{
				vector<int> fence(5,0);
				fence[0] = tempFences[j][0];
				fence[1] = tempFences[j][1];
				fence[2] = tempFences[j][2];
				fence[3] = i;
				fence[4] = 0;

				fences.push_back(fence);
			}
		}
	}

	vector<Edge *> adjList(M+1,NULL);

	for(int i = 0; i < fences.size(); ++i)
	{
		int pen1 = fences[i][3];
		int pen2 = fences[i][4];
		int cost = fences[i][2];
		insert_edge(&adjList[pen1],cost,pen2);
		insert_edge(&adjList[pen2],cost,pen1);

	}

	int minCost = prim(adjList,0,M);

	int minCostOutside = prim(adjList,1000000,M);

	if(minCostOutside < minCost)
	{
		minCost= minCostOutside;
	}

	cout << minCost << endl;
	
	return 0;
}
