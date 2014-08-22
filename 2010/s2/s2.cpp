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

	return 0;
}
