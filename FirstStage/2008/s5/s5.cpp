#include <iostream>
#include <vector>

using namespace std;

void recurse(vector<vector<vector<vector<int> > > > &particles, int A, int B, int C, int D)
{
	if(particles[A][B][C][D] != -1)
	{
		return;
	}
	else
	{
		int value = 0;
		bool gameOver = true;
		if(A >= 2 && B >= 1 && D >= 2)
		{
			recurse(particles,A-2,B-1,C,D-2);
			gameOver = false;
			if(particles[A-2][B-1][C][D-2]%2 == 0)
			{
				value = particles[A-2][B-1][C][D-2] + 1;
			}
		}
		if(A >= 1 && B >= 1 && C >= 1 && D >= 1)
		{
			recurse(particles,A-1,B-1,C-1,D-1);
			gameOver = false;
			if(particles[A-1][B-1][C-1][D-1]%2 == 0)
			{
				value = particles[A-1][B-1][C-1][D-1] + 1;
			}
		}
		if(C >= 2 && D >= 1)
		{
			recurse(particles,A,B,C-2,D-1);
			gameOver = false;
			if(particles[A][B][C-2][D-1]%2 == 0)
			{
				value = particles[A][B][C-2][D-1] + 1;
			}
		}
		if(B >= 3)
		{
			recurse(particles,A,B-3,C,D);
			gameOver = false;
			if(particles[A][B-3][C][D]%2 == 0)
			{
				value = particles[A][B-3][C][D] + 1;
			}
		}
		if(A >= 1 && D >= 1)
		{
			recurse(particles,A-1,B,C,D-1);
			gameOver = false;
			if(particles[A-1][B][C][D-1]%2 == 0)
			{
				value = particles[A-1][B][C][D-1] + 1;
			}
		}
		if(gameOver)
		{
			particles[A][B][C][D] = 0;
		}
		else
		{
			particles[A][B][C][D] = value;
		}
	}
}

int main()
{
	int n = 0;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		int A = 0;
		cin >> A;

		int B = 0;
		cin >> B;

		int C = 0;
		cin >> C;

		int D = 0;
		cin >> D;

		vector<int> empty1(D+1,-1);
		vector<vector<int> > empty2(C+1,empty1);
		vector<vector<vector<int> > > empty3(B+1,empty2);
		vector<vector<vector<vector<int> > > > particles(A+1,empty3);

		recurse(particles,A,B,C,D);

		if(particles[A][B][C][D]%2 == 1)
		{
			cout << "Patrick\n";
		}
		else
		{
			cout << "Roland\n";
		}

	}

	return 0;
}
