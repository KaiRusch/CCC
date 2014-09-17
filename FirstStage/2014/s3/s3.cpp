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

		// 'Y' if all carts can make it to the lake 'N' if not
		char state = 'Y';

		//While the puzzle is still possible and has not been completed
		while(state == 'Y' && lake != N)
		{
			//If the cart on the mountain can be moved to the lake, move it
			if(mountain.top() == lake + 1)
			{
				lake++;
				mountain.pop();
			}
			//If the carts on the branch can be moved to the lake move it
			else if(branch.top() == lake + 1)
			{
				lake++;
				branch.pop();
			}
			//If there is a cart on the mountain move it to the branch
			else if(mountain.size() > 1)
			{
				branch.push(mountain.top());
				mountain.pop();
			}
			//Otherwise it is impossible
			else
			{
				state = 'N';
			}
		}

		printf("%c\n",state);
	}
	return 0;
}
