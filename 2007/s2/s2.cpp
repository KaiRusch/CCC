#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	vector<vector<int> > boxes;

	for(int i = 0; i < n; ++i)
	{
		vector<int> box(3,0);

		int x = 0;
		cin >> x;
		int y = 0;
		cin >> y;
		int z = 0;
		cin >> z;

		box[0] = x;
		box[1] = y;
		box[2] = z;

		boxes.push_back(box);
	}

	int m = 0;
	cin >> m;

	for(int i = 0; i < m; ++i)
	{
		int x = 0;
		cin >> x;
		int y = 0;
		cin >> y;
		int z = 0;
		cin >> z;
		
		unsigned long long int volume = 8000000000;
		for(int j = 0; j < boxes.size(); ++j)
		{
			if((x<=boxes[j][0] && y <= boxes[j][1] && z <= boxes[j][2]) || (x <= boxes[j][1] && y <= boxes[j][2] && z <= boxes[j][0]) || (x <= boxes[j][0] && y <= boxes[j][2] && z <= boxes[j][1]) || (x <= boxes[j][2] && y <= boxes[j][0] && z <= boxes[j][1]) || (x <= boxes[j][1] && y <= boxes[j][0] && z <= boxes[j][2]) || (x <= boxes[j][2] && y <= boxes[j][1] && z <= boxes[j][0]))
			{
				unsigned long long int boxVolume = boxes[j][0] * boxes[j][1] * boxes[j][2];
				if(boxVolume < volume)
				{
					volume = boxVolume;
				}
			}	
		}

		if(volume == 8000000000)
		{
			cout << "Item does not fit.\n";
		}
		else
		{
			cout << volume << endl;
		}

	}

	return 0;
}
