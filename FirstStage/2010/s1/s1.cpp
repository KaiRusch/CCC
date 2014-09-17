#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	int bestScore = 0;
	string bestName = " ";

	int sBestScore = 0;
	string sBestName = " ";

	for(int i = 0; i < n; ++i)
	{
		string name = " ";
		cin >> name;

		int R = 0;
		cin >> R;

		int S  = 0;
		cin >> S;

		int D = 0;
		cin >> D;

		int score = 2*R + 3*S + D;

		if(score > bestScore || (score == bestScore && name.compare(bestName) < 0))
		{
			sBestScore = bestScore;
			sBestName = bestName;

			bestScore = score;
			bestName = name;
		}
		else if(score > sBestScore || (score == sBestScore && name.compare(sBestName) < 0))
		{
			sBestScore = score;
			sBestName = name;
		}
	}

	if(n > 1)
	{
		cout << bestName << endl << sBestName << endl;
	}
	else
	{
		cout << bestName << endl;
	}

	return 0;
}
