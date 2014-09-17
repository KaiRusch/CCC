#include <iostream>
#include <string>

using namespace std;

int main()
{
	int lowestTemp = 201;
	string lowestName = "Aurora";

	bool napoleonDefeated = false;
	while(!napoleonDefeated)
	{
		string name =  " ";
		cin >> name;

		int temp = 0;
		cin >> temp;

		if(temp < lowestTemp)
		{
			lowestTemp = temp;
			lowestName = name;
		}

		if(name == "Waterloo")
		{
			napoleonDefeated = true;
		}
	}

	cout << lowestName << endl;

	return 0;
}
