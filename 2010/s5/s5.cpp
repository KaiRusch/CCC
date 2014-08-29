#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Type{ROOT,BRANCH,LEAF};

class Node
{
	public:
		
		int ID;

		int type;

		int production;

		Node *parent;
		Node *left;
		Node *right;

		Node(int id, int t, Node *par, int p){ID = id; type = t; production = p; parent = par; left = NULL; right = NULL;};
};

Node *root = NULL;

int get_best_production(vector<vector<int> > &bestResults, Node *node, int growthAgents)
{
	if(node == NULL)
	{
		return 0;
	}

	int ID = node->ID;

	if(bestResults[ID][growthAgents] != 0)
	{
		return bestResults[ID][growthAgents];
	}

	else if (node->type == LEAF)
	{
		int production = node->production + growthAgents;
		bestResults[ID][growthAgents] = production;
		return production;
	}

	else if(node->type == BRANCH)
	{
		int capacity = 1;
		if(growthAgents == 0)
		{
			int production = get_best_production(bestResults,node->left,0) + get_best_production(bestResults,node->right,0);
			if(production > capacity)
			{
				production = capacity;
			}
			
			bestResults[ID][0] = production;
			return production;
		}
		
		else
		{
			int maxProduction = 0;

			for(int i = 0; i <= growthAgents; ++i)
			{
				for(int j = 0; j <= growthAgents - i; ++j)
				{

					capacity = (1+i)*(1+i); 
					int production = get_best_production(bestResults,node->left,j) + get_best_production(bestResults,node->right,growthAgents-j-i);
					if(production > capacity)
					{
						production = capacity;
					}

					if(production > maxProduction)
					{
						maxProduction = production;
					}
				}
			}

			bestResults[ID][growthAgents] = maxProduction;
			return maxProduction;
		}

	}

	else if(node->type == ROOT)
	{
		int maxProduction = 0;

		for(int i = 0; i <= growthAgents; ++i)
		{
			int production = get_best_production(bestResults,node->left,i) + get_best_production(bestResults,node->right,growthAgents-i);
			if(production > maxProduction)
			{
				maxProduction = production;
			}
		}

		return maxProduction;
	}
}

int main()
{
	string treeDescription = " ";
	getline(cin,treeDescription);

	root = new Node(0,ROOT,NULL,0);

	Node *current = root;

	//The number of nodes in the tree
	int nodes = 0;

	for(int i = 0; i < treeDescription.size(); ++i)
	{
		char input =  treeDescription[i];

		if(input == '(')
		{
			nodes++;
			current->left = new Node(nodes,BRANCH,current,0);
			current = current->left;
		}

		else if(input == ' ')
		{
			nodes++;
			current = current->parent;
			current->right = new Node(nodes,BRANCH,current,0);
			current =  current->right;
		}

		else if(input == ')')
		{
			current = current->parent;
		}

		else
		{
			int leafProduction = 0;

			while(input != '(' && input != ' ' && input != ')' && i < treeDescription.size())
			{
				leafProduction = leafProduction * 10 + (input - '0');
				i++;
				input = treeDescription[i];
			}

			i--;
			nodes++;
			current->left = new Node(nodes,LEAF,current,leafProduction);
		}
	}

	int X = 0;
	cin >> X;

	vector<int> empty(X+1,0);
	vector<vector<int> > bestAns(nodes+1,empty);

	cout << get_best_production(bestAns,root,X) << endl;

	return 0;
}
