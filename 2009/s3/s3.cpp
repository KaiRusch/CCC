#include <iostream>
#include <vector>

using namespace std;

int friends[51][51] = {0};

void insert_friend(int x, int y)
{
	friends[x][y] = 1;
	friends[y][x] = 1;
}

void delete_friend(int x, int y)
{
	friends[x][y] = 0;
	friends[y][x] = 0;
}

void print_friends(int x)
{
	int n = 0;

	for(int i = 0; i < 51; ++i)
	{
		if(friends[x][i] == 1)
		{
			n++;
		}
	}

	cout << n << endl;
}

void print_friends_of_friends(int x)
{
	int n = 0;
	int depth = 0;
	bool visited[51] = {false};
	vector<int> frontier(1,x);

	while(frontier.size() > 0 && depth < 2)
	{
		vector<int> next;
		for(int i = 0; i < frontier.size(); ++i)
		{
			int vertex = frontier[i];
			visited[vertex] = true;
			
			for(int j = 0; j < 51; ++j)
			{
				if(friends[vertex][j] == 1 && !visited[j])
				{
					if(depth == 1)
					{
						visited[j] = true;
						n++;
					}
					else
					{
						visited[j] = true;
						next.push_back(j);
					}
				}
			}
		}

		depth++;
		frontier = next;
	}

	cout << n << endl;
}

void print_seperation(int x, int y)
{
	vector<int> frontier;
	frontier.push_back(x);
	int level[51] = {0};

	while(frontier.size()>0)
	{
		vector<int> next;

		for(int i = 0; i < frontier.size(); ++i)
		{
			int vertex = frontier[i];

			if(vertex == y)
			{
				cout << level[y] << endl;
				return;
			}

			for(int j = 0; j < 51; ++j)
			{
				if(friends[vertex][j] == 1 && !level[j])
				{
					level[j] = level[vertex] + 1;
					next.push_back(j);
				}
			}
		}

		frontier = next;
	}

	cout << "Not connected\n";
}

void setup()
{
	insert_friend(1,6);
	insert_friend(2,6);
	insert_friend(3,4);
	insert_friend(3,5);
	insert_friend(3,6);
	insert_friend(3,15);
	insert_friend(4,5);
	insert_friend(4,6);
	insert_friend(5,6);
	insert_friend(6,7);
	insert_friend(7,8);
	insert_friend(8,9);
	insert_friend(9,10);
	insert_friend(9,12);
	insert_friend(10,11);
	insert_friend(11,12);
	insert_friend(12,13);
	insert_friend(13,14);
	insert_friend(13,15);
	insert_friend(16,17);
	insert_friend(16,18);
	insert_friend(17,18);
}

int main()
{
	setup();

	while(true)
	{
		char command = ' ';
		cin >> command;

		if(command == 'q')
		{
			break;
		}
		else if(command == 'i')
		{
			int x= 0, y = 0;
			cin >> x;
			cin >> y;
			insert_friend(x,y);
		}
		else if(command == 'd')
		{
			int x = 0, y = 0;
			cin >> x;
			cin >> y;
			delete_friend(x,y);
		}
		else if(command == 'n')
		{
			int x = 0;
			cin >> x;
			print_friends(x);
		}
		else if(command == 'f')
		{
			int x = 0;
			cin >> x;
			print_friends_of_friends(x);
		}
		else if(command == 's')
		{
			int x = 0, y = 0;
			cin >> x;
			cin >> y;
			print_seperation(x,y);
		}
	}	

	return 0;
}
