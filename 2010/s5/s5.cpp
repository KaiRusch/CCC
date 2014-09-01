#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node
{
	public:
		
		int ID;
		int production;

		Node *left;
		Node *right;

		Node(int id, int p){ID = id; production = p; left = NULL; right = NULL;};
};



void get_best_production(vector<vector<int> > &bestResults, Node *node, int growthAgents)
{
	if (node->left->left == NULL)
	{
		for(int i = 0; i <= growthAgents; ++i)
		{
			int production = node->left->production + i;
			bestResults[node->ID][i] = production;
		}

		return;
	}

	else
	{
		int max = 0;
		int temp = 0;

		vector<int> leftBest(growthAgents+1,0);

		if(node->left != NULL)
		{
			get_best_production(bestResults,node->left,growthAgents);
			for(int i = 0; i <= growthAgents; ++i)
			{
				for(int j = 0; j <= i; ++j)
				{
					int capacity = (1+j)*(1+j);
					if(capacity < bestResults[node->left->ID][i-j])
					{
						temp = capacity;
					}
					else
					{
						temp = bestResults[node->left->ID][i-j];
					}
					if(temp > max)
					{
						max = temp;
					}
				}

				leftBest[i] = max;
			}
		}

		vector<int> rightBest(growthAgents+1,0);
		
		if(node->right != NULL)
		{
			get_best_production(bestResults,node->right,growthAgents);
			for(int i = 0; i <= growthAgents; ++i)
			{
				max = 0;
				for(int j = 0; j <= i; ++j)
				{
					int capacity = (1+j)*(1+j);
					if(capacity < bestResults[node->right->ID][i-j])
					{
						temp = capacity;
					}
					else
					{
						temp = bestResults[node->right->ID][i-j];
					}
					if(temp > max)
					{
						max = temp;
					}
				}

				rightBest[i] = max;
			}
		}

		for(int i = 0; i <= growthAgents; ++i)
		{
			max = 0;
			for(int j = 0; j <= i; ++j)
			{
				temp = leftBest[j] + rightBest[i-j];
				if(temp > max)
				{
					max = temp;
				}
			}

			bestResults[node->ID][i] = max;
		}
	}
}

void create_tree(string description, Node *parent, int &nodes)
{
	if(description[0] != '(')
	{
		int value = 0;
		int i = 0;
		while(i < description.size() && (description[i] != '(' && description[i] != ')' && description[i] != ' '))
		{
			value = value *10 + (description[i] - '0');
			i++;
		}

		nodes++;
		parent->left = new Node(nodes,value);
	}
	else
	{
		description.erase(description.end()-1);
		description.erase(description.begin());

		if(description[0] == ' ')
		{
			description.erase(description.begin());
		}

		string leftDescription = " ";
		string rightDescription = " ";

		int i = 0;
		if(description[0] == '(')
		{
			int count = 1;
			i = 1;
			while(count > 0)
			{
				if(description[i] == '(')
				{
					count++;
				}
				else if(description[i] == ')')
				{
					count--;
				}
				i++;
			}
		}
		else
		{
			i = description.find_first_of(' ');
		}

		leftDescription = description.substr(0,i);
		rightDescription = description.substr(i+1,description.length()-i);
	
		nodes++;
		parent->left = new Node(nodes,0);
		nodes++;
		parent->right = new Node(nodes,0);

		create_tree(leftDescription,parent->left,nodes);
		create_tree(rightDescription,parent->right,nodes);
	}
}

Node *root = NULL;

int main()
{
	string description = " ";
	getline(cin,description);

	root = new Node(0,0);

	int nodes = 0;

	create_tree(description,root,nodes);

	int X = 0;
	cin >> X;

	vector<int> empty(X+1,0);
	vector<vector<int> > bestAns(nodes+1,empty);

	get_best_production(bestAns,root,X);

	cout << bestAns[root->ID][X] << endl;

	return 0;
}
