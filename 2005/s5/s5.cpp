#include <iostream>
#include <vector>

using namespace std;

class Node
{
	public:
		long long int score;
		long long int rank;
		Node *greater;
		Node *lesser;
		Node(int s) {score = s; rank = 0; greater = NULL; lesser = NULL;};
};

void clean_up(Node *node)
{
	if(node == NULL)
	{
		return;
	}
	else
	{
		clean_up(node->greater);
		clean_up(node->lesser);
		delete(node);
	}
}

int add_node(Node *(&node), long long int score)
{
	if(node == NULL)
	{
		node = new Node(score);
		return 0;
	}
	else
	{	
		long long int rank = 0;

		Node *current = node;

		while(true)
		{
			if(score < current->score)
			{
				rank += current->rank + 1;
				if(current->lesser == NULL)
				{
					current->lesser = new Node(score);
					return rank;
				}
				else
				{
					current = current->lesser;
				}
			}
			else
			{
				current->rank++;
				if(current->greater == NULL)
				{
					current->greater = new Node(score);
					return rank;
				}
				else
				{
					current = current->greater;
				}
			}
		}
	}
}

int main()
{
	int t = 0;
	cin >> t;

	Node *root = NULL;

	long long int totalRank = 0;

	for(int i = 0; i < t; ++i)
	{
		long long int score = 0;
		cin >> score;

		totalRank += add_node(root,score) + 1;

	}
	
	cout << (long double)totalRank/t << endl;

	return 0;
}
