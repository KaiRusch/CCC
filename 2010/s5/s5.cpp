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

		Node *left;
		Node *right;

		Node(int id, int t, int p){ID = id; type = t; production = p; left = NULL; right = NULL;};
};



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
		parent->left = new Node(nodes,LEAF,value);
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
		parent->left = new Node(nodes,BRANCH,0);
		nodes++;
		parent->right = new Node(nodes,BRANCH,0);

		create_tree(leftDescription,parent->left,nodes);
		create_tree(rightDescription,parent->right,nodes);
	}
}

Node *root = NULL;

int main()
{
	string description = " ";
	getline(cin,description);

	root = new Node(0,ROOT,0);

	int nodes = 0;

	create_tree(description,root,nodes);

	int X = 0;
	cin >> X;

	vector<int> empty(X+1,0);
	vector<vector<int> > bestAns(nodes+1,empty);

	cout << get_best_production(bestAns,root,X) << endl;

	return 0;
}
