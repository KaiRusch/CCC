#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a = 0;
	cin >> a;

	int b = 0;
	cin >> b;

	int n = 0;

	int i = (int)sqrt(cbrt((double)a))+1;

	int cubeRoot = (int)cbrt((double)a);
	if(cubeRoot* cubeRoot * cubeRoot == a || (cubeRoot+1)*(cubeRoot+1)*(cubeRoot+1) == a)
	{
		int squareRoot = (int)sqrt((double)a);
		if(squareRoot*squareRoot == a || (squareRoot+1)*(squareRoot+1) == a)
		{
			n++;
		}
	}

	while(pow(i,6) <= b)
	{
		n++;
		i++;
	}

	cout << n << endl;

	return 0;
}
