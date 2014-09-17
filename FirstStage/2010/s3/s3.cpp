#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int H = 0;
	cin >> H;

	vector<int> houses;

	for(int i = 0; i < H; ++i)
	{
		int house = 0;
		cin >> house;
		houses.push_back(house);
	}

	int k = 0;
	cin >> k;

	return 0;
}
