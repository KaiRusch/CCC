#include <iostream>
#include <string>

using namespace std;

class Node
{
	public:
		char character;
		Node *zero;
		Node *one;

	Node(char c) {character = c; zero = NULL; one = NULL;};
};

Node *root = new Node(' ');

void clean_up(Node *node)
{
	if(node != NULL)
	{
		Node *temp = node;
		Node *node0 = node->zero;
		Node *node1 = node->one;
		clean_up(node0);
		clean_up(node1);
		delete(temp);
	}
}

int main()
{
	int k  = 0;
	cin >> k;

	for(int i = 0; i < k; ++i)
	{

		char c = ' ';
		cin >> c;

		string code = " ";
		cin >> code;

		Node **current = &root;

		for(int j = 0; j < code.length(); ++j)
		{
			if(code[j] == '0')
			{	
				if(*current == NULL)
				{
					*current = new Node(' ');
				}
				current = &((*current)->zero);
			}
			else
			{
				if(*current == NULL)
				{
					*current = new Node(' ');
				}
				current = &((*current)->one);
			}
		}

		*current = new Node(c);
	}

	string text = " ";
	cin >> text;

	Node * current = root;

	for(int i = 0; i < text.length(); ++i)
	{
		if(text[i] == '0')
		{
			current = current->zero;
		}
		else
		{
			current = current->one;
		}

		if(current->zero == NULL && current->one == NULL)
		{
			cout << current->character;
			current = root;
		}
	}

	cout << endl;

	clean_up(root);

	return 0;
}
