#include <iostream>
#include <vector>

using namespace std;

//Class for the graph's edge
class Edge
{
	public:
		//The weight of the edge
		int cost;
		//The vertex it connects to
		int vertex;
		
		//Points to next edge in adjacency list
		Edge *next;

		Edge(int c, int v){cost = c; vertex = v; next = NULL;};
};

//Inserts an edge into the adjacency list
void insert_edge(Edge **head, int c, int v)
{
	Edge *temp = *head;
	*head = new Edge(c,v);
	(*head)->next = temp;
}

int prim(vector<Edge *> &adjList, int vertexToSkip, int M)
{
	//The total cost of the minimum spanning tree
	int minCost = 0;

	//If the outside pen is included
	if(vertexToSkip!=0)
	{
		//We're checking M+1 pens
		M++;
	}

	//The first vertex in the tree is pen 1
	//Vector containing the vertices already in the tree
	vector<int> verticesInTree (1,1);
	//Boolean vector to lookup if vertex is in the tree
	vector<bool> addedVertices (M+1,false);
	addedVertices[1] = true;

	//While there are still pens left to visit
	while(verticesInTree.size() < M)
	{
		//Set the worst possible cost
		int minEdgeCost = 5001;
		//Set defulat vertex to 0, in case of seperate gorups of pens connected
		//only by the outside this will ensure a terrible cost if we are avoiding the outside
		int minEdgeVertex = 0;

		//Cycle through all vertices in the tree
		for(int i = 0; i < verticesInTree.size(); ++i)
		{
			//Cycle through all the edges connected to that vertex
			int vertex = verticesInTree[i];
			Edge *current = adjList[vertex];

			while(current != NULL)
			{
				//If the cost of the edge is better than the best, we haven't visited it, and it's
				//the outside vertex if we're avoidin gthe outside
				if(current->cost < minEdgeCost && current->vertex != vertexToSkip && !addedVertices[current->vertex])
				{
					//Update the minimum cost and vertex
					minEdgeCost = current->cost;
					minEdgeVertex = current->vertex;
				}
				current = current->next;
			}
		}

		//Add the best edge and vertex to the tree
		minCost+=minEdgeCost;
		verticesInTree.push_back(minEdgeVertex);
		addedVertices[minEdgeVertex] = true;

	}

	//Return the total cost of the tree
	return minCost;
}

int main()
{
	//Read the number of pens/animals
	int M = 0;
	cin >> M;

	//0 = corner, 1 = corner, 2 = cost, 3 = pen, 4 = pen
	vector<vector<int> > fences;

	for(int i = 1; i <= M; ++i)
	{
		//Read the number of fences composin the pen
		int e = 0;
		cin >> e;

		//A vector containing the corners of the pen
		vector<int> corners(e,0);

		//Read the corners
		for(int j = 0; j < e; ++j)
		{
			int corner = 0;
			cin >> corner;
			corners[j] = corner;
		}

		//Vector containing the fences surrounding the current (ith) pen
		vector<vector<int> > tempFences;

		//Read the fences
		for(int j = 0; j < e; ++j)
		{
			//The cost of breaking the fence
			int cost = 0;
			cin >> cost;

			//0 = corner, 1 = corner, 2 = cost
			vector<int> fence(3,0);

			//Set the first corner of the edge and its cost
			fence[0] = corners[j];
			fence[2] = cost;

			//If the first corner of the fence is the last corner in the corner vector
			if(j == e-1)
			{
				//Have it warp around
				fence[1] = corners[0];
			}
			else
			{
				//Otherwise set the second corner to the following corner
				fence[1] = corners[j+1];
			}
			
			//Add the fence to the vector
			tempFences.push_back(fence);
		}

		//Cycles through the tempFences to check if they are duplicates of fences in 
		//the fences vector
		for(int j = 0; j < e; ++j)
		{
			bool duplicate = false;
			int k = 0;
			//Checks if the fence is a duplicate
			while(!duplicate && k < fences.size())
			{
				if((tempFences[j][0] == fences[k][0] && tempFences[j][1] == fences[k][1])||(tempFences[j][0] == fences[k][1] && tempFences[j][1] == fences[k][0]))
						{
							duplicate = true;
						}
				k++;
			}

			//If it is a duplicate set the fences second vertex to the current (ith) pen
			if(duplicate)
			{
				fences[k-1][4] = i;
			}
			//Otherwise add a new fence to the vector and set the first vertex to the current
			//(ith) pen
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

	//The adjaceny list head pointers vector
	vector<Edge *> adjList(M+1,NULL);

	//Transfer the data from the fences vector to the adjacency list
	for(int i = 0; i < fences.size(); ++i)
	{
		int pen1 = fences[i][3];
		int pen2 = fences[i][4];
		int cost = fences[i][2];
		insert_edge(&adjList[pen1],cost,pen2);
		insert_edge(&adjList[pen2],cost,pen1);

	}

	//Find the minimum cost if the animals don't go outside
	int minCost = prim(adjList,0,M);

	//Find the minimum cost if the animals go outside
	int minCostOutside = prim(adjList,1000000,M);

	//Find the lowest cost
	if(minCostOutside < minCost)
	{
		minCost= minCostOutside;
	}

	//Print the answer
	cout << minCost << endl;
	
	return 0;
}
