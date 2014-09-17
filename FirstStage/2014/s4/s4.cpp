#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	int N = 0;
	cin >> N;

        int T = 0;
	cin >> T;

	vector<vector<unsigned long long int> > glassEdges;

	vector<int> yValues;

	for(int i = 0; i < N; ++i)
	{
		vector<unsigned long long int> incomingEdge(4,0);
		vector<unsigned long long int> outcomingEdge(4,0);

		int x1 = 0, y1 = 0, x2 = 0, y2 = 0, tint = 0;
		cin >> x1 >> y1 >> x2 >> y2 >> tint;

		incomingEdge[0] = x1;
		incomingEdge[1] = y1;
		incomingEdge[2] = y2;
		incomingEdge[3] = tint;

		outcomingEdge[0] = x2;
		outcomingEdge[1] = y1;
		outcomingEdge[2] = y2;
		outcomingEdge[3] = -tint;

		glassEdges.push_back(incomingEdge);
		glassEdges.push_back(outcomingEdge);

		int j = 0;
		bool foundY1 = false, foundY2 = false;
		while(j < yValues.size() && (!foundY1 || ! foundY2))
		{
			if(yValues[j] == y1)
			{
				foundY1 = true;
			}
			if(yValues[j] == y2)
			{
				foundY2 = true;
			}
			j++;
		}

		if(!foundY1)
		{
			yValues.push_back(y1);
		}
		if(!foundY2)
		{
			yValues.push_back(y2);
		}
	}

	sort(glassEdges.begin(),glassEdges.end());

	sort(yValues.begin(), yValues.end());

	map<int,int> yMap;

	for(int i = 0; i < yValues.size(); ++i)
	{
		yMap[yValues[i]] = i;
	}

	vector<int> yTints(yValues.size(),0);

	unsigned long long int area = 0;

	for(int i = 0; i < glassEdges.size(); ++i)
	{
		for(int j = 0; j < yTints.size(); ++j)
		{
			if(yTints[j] >= T)
			{
				area += ((yValues[j+1]-yValues[j])*(glassEdges[i][0] - glassEdges[i-1][0]));
			}
		}
		for(int j = yMap[glassEdges[i][1]]; j < yMap[glassEdges[i][2]]; ++j)
		{
			yTints[j] += glassEdges[i][3];
		}
	}

	cout << area << endl;

	return 0; 
}
