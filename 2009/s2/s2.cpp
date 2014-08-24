#include <iostream>
#include <vector>

using namespace std;

vector<int> xOR(vector<int> k, vector<int> l)
{
	vector<int> newRow;

	for(int i = 0; i < k.size(); ++i)
	{
		if(k[i] == l[i])
		{
			newRow.push_back(0);
		}
		else
		{
			newRow.push_back(1);
		}
	}

	return newRow;

}

bool compare(vector<vector<int> > &possibilities, vector<int> possibility)
{
	bool duplicate = false;
	int i = 0;
	while(!duplicate && i < possibilities.size())
	{
		bool identical= true;
		int j = 0;
		while(identical && j <  possibilities[i].size())
		{
			if(possibilities[i][j] != possibility[j])
			{
				identical = false;
			}
			j++;
		}
		if(identical)
		{
			duplicate = true;
		}
		i++;
	}

	return duplicate;
}

int main()
{
	int R = 0;
	cin >> R;
	int L = 0;
	cin >> L;

	vector<vector<int> > lights;

	for(int i = 0; i < R; ++i)
	{
		vector<int> row;
		for(int j = 0; j < L; ++j)
		{
			int light = 0;
			cin >> light;
			row.push_back(light);
		}

		lights.push_back(row);
	}

	vector<vector<int> > topPos(1,lights[0]);
	vector<vector<int> > bottomPos;

	for(int i = 1; i < R; ++i)
	{
		bottomPos.push_back(lights[i]);
		for(int j = 0; j < topPos.size(); ++j)
		{
			if(!compare(bottomPos,xOR(lights[i],topPos[j])))
			{
				bottomPos.push_back(xOR(lights[i],topPos[j]));
			}
		}

		topPos = bottomPos;
		bottomPos.clear();

	}

	cout << topPos.size() << endl;

	return 0;
}
