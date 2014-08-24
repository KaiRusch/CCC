#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int N = 0;
	cin >> N;

	int cost = 0;

	while(N > 1)
	{
		int upperBound = int(sqrt(N))+1;
		int f = 2;
		
		while(f <= upperBound && N%f!=0)
		{
			f++;
		}

		if(f < N && N%f == 0)
		{
			int factor = N/f;
			N = N - factor;
			cost = cost + N/factor;
		}
		else
		{
			N--;
			cost = cost + N;
		}


	}

	cout << cost << endl;

	return 0;
}

