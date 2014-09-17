#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t = 0;
	cin >> t;

	for(int i = 0; i < t; ++i)
	{
		string number = " ";
		cin >> number;
		string newNumber = "";

		for(int j = 0; j < number.length(); ++j)
		{
			char digit = number[j];
			if(digit!= '-')
			{
				if(digit > '9')
				{
					if(digit >= 'A' && digit <= 'C')
					{
						digit = '2';
					}
					else if(digit >= 'D' && digit <= 'F')
					{
						digit = '3';
					}
					else if(digit >= 'G' && digit <= 'I')
					{
						digit = '4';
					}
					else if(digit >= 'J' && digit <= 'L')
					{
						digit = '5';
					}
					else if(digit >= 'M' && digit <= 'O')
					{
						digit = '6';
					}
					else if(digit >= 'P' && digit <= 'S')
					{
						digit = '7';
					}
					else if(digit >= 'T' && digit <= 'V')
					{
						digit = '8';
					}
					else if(digit >= 'W')
					{
						digit = '9';
					}
				}
				newNumber.push_back(digit);
				if(newNumber.length() == 3 || newNumber.length() == 7)
				{
					newNumber.push_back('-');
				}

				if(newNumber.length() == 12)
				{
					break;
				}
			}
		}

		cout << newNumber << endl;
	}
	return 0;
}
