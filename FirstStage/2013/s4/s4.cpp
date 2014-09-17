#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//Node of linked list
class Node
{
	public:
		//The value of the vertex (ie which student)
		int vertex;
		//Pointer to the next vertex in the list
		Node *next;

		Node(int v){vertex = v; next = NULL;};
};

//Inserts node in linked list of edges, of a vertex
//X is the vertex which points to Y (the edge is (x,y))
void insertNode(vector<Node*> &graph, int x,int y)
{
	//Pointer to head pointer of list
	Node **head = &graph[x];

	//If the head points to NULL
	if(*head == NULL)
	{
		//Simply point it to a new node
		*head = new Node(y);
	}
	else
	{
		//Otherwise insert the new node at the front of the list
		Node *temp = *head;
		*head = new Node(y);
		(*head)->next = temp;
	}
}

bool search(vector<Node *> &graph, int N, int p, int q)
{
	//Queue containing the vertex to visit
	queue<int> next;
	next.push(p);
	//Boolean value for all vectors, false if they have not been visited
	vector<bool> visited(N+1,false);

	//While there are vertices in the queue
	while(next.size() > 0)
	{
		int vertex = next.front();
		//Set the visited flag to true for the current vertex
		visited[vertex] = true;
		//Pointer to current place in the linked list of the vertex
		Node *current = graph[vertex];
		//While there are still nodes in the list
		while(current != NULL)
		{
			//If q has been found return true
			if(current->vertex == q)
			{
				return true;
			}
			//Otherwise if the vertex has not been visited
			//Add it to the queue
			else if(visited[current->vertex] == false)
			{
				next.push(current->vertex);
			}
			//Travel down the linked list
			current = current->next;
		}
		//Erase the current vertex from the queue
		next.pop();
	}

	return false;
	
}

int main()
{
	//Read the number of students (vertices)
	int N = 0;
	cin >> N;
	//Read the number of comparisons made (edges)
	int M = 0;
	cin >> M;

	//Create a vector for each vertex containing a pointer to a linked list
	//which contains all the edges outgoing from that vertex
	//AKA: adjacency list
	//Edges are directed, going from larger to shorter students
	vector<Node*> graph(N+1,NULL);

	//For all comparisons
	for(int i = 0; i < M; ++i)
	{
		//Read the taller and shorter student
		int x = 0;
		cin >> x;
		int y = 0;
		cin >> y;
		
		//Insert the node into the list
		insertNode(graph,x,y);
	}

	//Read the students which we are curious about
	int p = 0;
	cin >> p;
	int q = 0;
	cin >> q;

	//If q can be found from starting location p
	//then p is taller than q
	if(search(graph,N,p,q))
	{
		cout << "yes\n";
	}
	//If p can be found from starting location q
	//Then q is taller than p
	else if(search(graph,N,q,p))
	{
		cout << "no\n";
	}
	//Otherwise they are not connected in any way
	//So it is unknown which is taller
	else
	{
		cout << "unknown\n";
	}

	return 0;
}
