#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	while(true)
	{
		int r = 0;
		cin >> r;
		if(r == 0)
		{
			break;
		}

		int coins = 0;

		int rSquared = r*r;

		for(int i = 0; i <= r; ++i)
		{
			coins += (int)sqrt((double)rSquared - i*i);
		}

		cout << coins*4 + 1 << endl;
	}

	return 0;
}
