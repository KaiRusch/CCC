#include <iostream>
#include <vector>

using namespace std;

int main()
{
	//Read the number of students in the class
	int n = 0;
	cin >> n;

	//Vector containing the friendships,
	//simple adjacency matrix, as there is only one edge 
	//going out of each vertex
	vector<int> friends(n+1,0);

	//While the quit flag hasn't been thrown
	bool quit = false;
	while(!quit)
	{	
		//Read the two students
		int x = 0;
		cin >> x;
		int y = 0;
		cin >> y;

		//If it's the end of input
		//Throw the quit flag
		if(x == 0 && y == 0)
		{
			quit = true;
		}
		else
		{
			//If student x has no friends
			//Set student y as his friend
			if(friends[x] == 0)
			{
				friends[x] = y;
			}
			else
			{
				//The degrees of seperation
				int d = 0;
				//The current student, starts at x
				int student = x;
				//While the connection between x and y hasn't been made, or we returned to student x
				//Or reached a student without a friend
				while(friends[student] != y && friends[student] != 0 && friends[student] != x)
				{
					//Got to the currents students friend
					student = friends[student];
					//Increase the degree of seperation
					d++;
				}
				//If we've returned to x or hit a dead end output "No"
				if(friends[student] == 0 || friends[student] == x)
				{
					cout << "No\n";
				}
				//Otherwise print "Yes"
				else
				{
					cout << "Yes\n" << d << endl;
				}
			}
		}
	}	

	return 0;
}
