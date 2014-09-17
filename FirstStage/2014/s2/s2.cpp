#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])	
{
	//Read the number of students
	int N = 0;
	scanf("%d",&N);

	//The first line of student names
	string  first[30];
	//The second line of student names
	string second[30];

	//Read the first line of names
	for(int i = 0; i < N; ++i)
	{
		cin >> first[i];
	}
	
	//Read the second line of names
	for(int i = 0; i < N; ++i)
	{
		cin >> second[i];
	}

	//The state of the partner assignment
	string state = "good";

	int i = 0;
	while(i < N && state == "good")
	{
		//The partner of the student in the first line
		string partner = second[i];
		
		//Search first line for partner
		int j = 0;
		while(j < N && first[j] != partner)
		{
			j++;
		}

		//Check if the partner in the first line is not paired up with the original
		//student in the second line
		//or if student is paired with themself
		if(second[j] != first[i] || first[i] == first[j])
		{
			state = "bad";
		}
		i++;
	}

	cout << state << endl;

	return 0;
}
