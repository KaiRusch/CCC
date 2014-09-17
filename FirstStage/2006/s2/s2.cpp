#include <iostream>
#include <string>

using namespace std;

int main()
{
	char convert[27];

	for(int i = 0; i < 27; ++i)
	{
		convert[i] = '.';
	}

	string normalText = " ";
	getline(cin,normalText);

	string cipherText = " ";
	getline(cin,cipherText);

	cout << normalText << endl;

	for(int i = 0; i < normalText.length(); ++i)
	{

		if(cipherText[i] != ' ')
		{
			convert[cipherText[i]-'A'] = normalText[i];
		}

		else
		{
			convert[26] = normalText[i];
		}

	}

	string message = " ";
	getline(cin,message);


	for(int i = 0; i < message.length(); ++i)
	{
		if(message[i] != ' ')
			message[i] = convert[message[i]-'A'];
		else
			message[i] = convert[26];
	}


	cout << message << endl;

	return 0;
}
