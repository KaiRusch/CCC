#include <iostream>
#include <string>

using namespace std;

int main()
{
	string alice = " ";
	cin >> alice;

	string bob = " ";
	cin >> bob;

	int x = 0;
	cin >> x;

	for(int i = 0; i < x; ++i)
	{
		string baby = " ";
		cin >> baby;

		bool isChild = true;

		for(int j = 0; j < 5; ++j)
		{
			char appearance = baby[j];
			
			if((appearance > alice[j*2] && appearance > alice[j*2 + 1]) || (appearance > bob[j*2] && appearance > bob[j*2 +1]))
			{
				isChild = false;
				break;
			}

			if(appearance < alice[j*2] && appearance < alice[j*2+1] && appearance < bob[j*2] && appearance < bob[j*2 +1])
			{
				isChild = false;
				break;
			}

		}

		if(isChild)
		{
			cout << "Possible baby.\n";
		}
		else
		{
			cout << "Not their baby!\n";
		}
	}

	return 0;
}
