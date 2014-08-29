#include <iostream>

using namespace std;

class Leaf
{
	public:
		int nutrients;

		Leaf(int n){nutrients = n;};
};

class Branch
{
	public:
		int capacity;

		Branch *branchLeft;
		Branch *branchRight;

		Leaf *leafLeft;
		Leaf *leafRight;

		Branch() {capacity = 1; branchLeft = NULL; branchRight = NULL; leafLeft = NULL; leafRight = NULL;}
};

class Root
{
	public:
		Branch *branchRight;
		Branch *branchLeft;

		Root() {branchRight = NULL; branchLeft = NULL;};
};

Root root;

void create_tree(bool rightBranch)
{

}

int main()
{
	bool rightBranch = false;

	char input = ' ';
	cin >> input;
	
	create_tree(input,rightBranch);
	return 0;
}
