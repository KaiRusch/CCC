#include <stdio.h>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
	//Read the aromatic number
	string number;	
	cin >> number;

	//The decimal value of the aromatic number
	int value = 0;

	//Map containing Roman number and corresponding decimal number
	map<char,int> conversion;

	conversion['I'] = 1;
	conversion['V'] = 5;
	conversion['X'] = 10;
	conversion['L'] = 50;
	conversion['C'] = 100;
	conversion['D'] = 500;
	conversion['M'] = 1000;

	for(int i = 0; i < number.length(); i = i + 2)
	{
		if(i <= number.length() - 3 && conversion[number[i+1]] < conversion[number[i+3]])
		{
			value-= (number[i]- '0') * conversion[number[i+1]];
		}
		else
		{	
			value+= (number[i]- '0') * conversion[number[i+1]];
		}
	}

	//Print value of the number
	printf("%d\n",value);

	return 0;
}
