#include <stdio.h>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	//Read the max weight the bridge can hold
	int W = 0;
	scanf("%d",&W);

	//Read the number of carts to move across the bridge
	int N = 0;
	scanf("%d",&N);

	//The weights of the carts
	vector<int> carts(3,0);

	//Read the weights of the carts
	for(int i = 0; i < N; ++i)
	{
		int cart = 0;
		scanf("%d",&cart);
		carts.push_back(cart);
	}

	//The number of carts which have crossed
	int crossed = 0;


	//Iterate through the carts and check if they are heavier than W
	//If not increment crossed
	
	int i = 0;	
	while(carts[i] + carts[i+1] + carts[i+2] + carts[i+3] <= W && i <  N - 2)
	{
		i++;
		crossed++;
	}

	//Print the result
	printf("%d\n",crossed);

	return 0;
}
