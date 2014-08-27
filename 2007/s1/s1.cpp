#include <iostream>

using namespace std;

int main()
{
	int y = 2007;
	int m = 2;
	int d = 27;

	int n = 0;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		int year = 0;
		cin >> year;

		int month = 0;
		cin >> month;

		int day = 0;
		cin >> day;

		if(y - year >= 19)
		{
			cout << "Yes\n";
		}
		else if(y - year == 18)
		{
			if(month < m)
			{
				cout << "Yes\n";
			}
			else if(month == m)
			{
				if(day <= d)
				{
					cout << "Yes\n";
				}
				else
				{
					cout << "No\n";
				}

			}
			else
			{
				cout << "No\n";
			}
		}
		else
		{
			cout << "No\n";
		}
	}

	return 0;
}
