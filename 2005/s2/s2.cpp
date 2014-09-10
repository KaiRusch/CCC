#include <iostream>

using namespace std;

int main()
{
	int c = 0;
	cin >> c;

	int r = 0;
	cin >> r;

	int x = 0;
	cin >> x;
	int y = 0;
	cin >> y;

	int xPos = 0;
	int yPos = 0;

	while(x!=0 || y!=0)
	{
		xPos += x;
		yPos += y;

		if(xPos < 0)
			xPos = 0;
		if(yPos < 0)
			yPos = 0;
		if(xPos > c)
			xPos = c;
		if(yPos > r)
			yPos = r;

		cout << xPos <<" "<<yPos << endl;
		

		cin >> x;
		cin >> y;
	}

	return 0;
}
