#include <stdio.h>
#include <stack>

using namespace std;

int main(int argc, char *argv[])
{
	//Read the number of tests
	int T = 0;
	scanf("%d",&T);

	//Run the tests
	for(int i = 0; i < T; ++i)
	{
		//The carts on the mountain
		stack<int> mountain;
		mountain.push(0);
		//The carts on the branch
		stack<int> branch;
		branch.push(0);
		//The top carts in the lake
		int lake = 0;
		
		//Read the number of carts
		int N = 0;
		scanf("%d",&N);


		//Read the carts
		for(int j = 0; j < N; ++j)
		{
			int cart = 0;
			scanf("%d",&cart);
			mountain.push(cart);
		}

		char state = 'Y';

		while(state == 'Y' && lake != N)
		{
			if(mountain.top() == lake + 1)
			{
				lake++;
				mountain.pop();
			}
			else if(branch.top() == lake + 1)
			{
				lake++;
				branch.pop();
			}
			else if(mountain.size() > 1)
			{
				branch.push(mountain.top());
				mountain.pop();
			}
			else
			{
				state = 'N';
			}
		}

		printf("%c\n",state);
	}
	return 0;
}
