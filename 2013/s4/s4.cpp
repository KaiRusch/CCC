#include <iostream>
#include <vector>

using namespace std;

class Node
{
	public:
		int vertex;
		Node *next;

		Node(int v){vertex = v; next = NULL;};
};

void insertNode(vector<Node*> &graph, int x,int y)
{
	Node **current = &graph[x];
	while(*current != NULL)
	{
		current = &((*current)->next);
	}
	*current = new Node(y);

}

bool search(vector<Node *> &graph, int N, int p, int q)
{
	vector<int> queue(1,p);
	vector<bool> visited(N+1,false);

	while(queue.size() > 0)
	{
		visited[queue[0]] = true;
		Node *current = graph[queue[0]];
		while(current != NULL)
		{
			if(current->vertex == q)
			{
				return true;
			}
			else if(visited[current->vertex] == false)
			{
				queue.push_back(current->vertex);
			}
			current = current->next;
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

	vector<Node*> graph(N+1,NULL);

	for(int i = 0; i < M; ++i)
	{
		int x = 0;
		cin >> x;
		int y = 0;
		cin >> y;

		insertNode(graph,x,y);
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
