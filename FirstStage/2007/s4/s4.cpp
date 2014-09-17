#include <iostream>
#include <vector>

using namespace std;

class Node
{
	public:
		int ID;
		Node *next;

		Node(int id){ID = id; next = NULL;};
};

void insert_node(Node **head, int id)
{
	Node *temp = *head;
	*head = new Node(id);
	(*head)->next = temp;

}

int recurse(vector<int> &possiblePaths, vector<Node *> &adjList, int vertex)
{
	if(possiblePaths[vertex] != 0)
	{
		return possiblePaths[vertex];
	}

	int paths = 0;
	Node *current = adjList[vertex];

	while(current!= NULL)
	{
		paths += recurse(possiblePaths,adjList,current->ID);
		current = current->next;

	}

	possiblePaths[vertex] = paths;

	return paths;
}

int main()
{
	int n = 0;
	cin >> n;

	vector<Node *> adjList(n+1,NULL);

	while(true)
	{
		int x  = 0;
		cin >> x;
		int y = 0;
		cin >> y;

		if(x == 0 && y == 0)
		{
			break;
		}
		else
		{
			insert_node(&adjList[x],y);
		}

	}

	vector<int> possiblePaths(n+1,0);
	possiblePaths[n] = 1;	

	recurse(possiblePaths,adjList,1);

	cout << possiblePaths[1] << endl;

	for(int i = 1; i <= n; ++i)
	{
		Node *current = adjList[i];
		while(current != NULL)
		{
			Node *temp = current;
			current = current->next;
			delete(temp);
		}
	}
	return 0;
}
