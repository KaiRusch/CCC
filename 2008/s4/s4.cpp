#include <iostream>
#include <vector>

using namespace std;

int answer = 0;

void shuffle(vector<int> cards, vector<int> deck, vector<bool> usedCards);

void rpn(vector<int> cards)
{
	if(cards.size() == 1)
	{
		if(cards[0] > answer && cards[0] <= 24)
		{
			answer = cards[0];
		}
	}
	else
	{
		int a =  cards.back();
		cards.pop_back();
		int b = cards.back();
		cards.pop_back();

		vector<bool> usedCards(cards.size()+1,false);
		vector<int> deck;

		cards.push_back(a+b);
		shuffle(cards,deck,usedCards);

		cards.pop_back();
		cards.push_back(a-b);
		shuffle(cards,deck,usedCards);

		cards.pop_back();
		cards.push_back(a*b);
		shuffle(cards,deck,usedCards);

		if(b!= 0 && a%b == 0)
		{
			cards.pop_back();
			cards.push_back(a/b);
			shuffle(cards,deck,usedCards);
		}
	}
}

void shuffle(vector<int> cards, vector<int> deck, vector<bool> usedCards)
{
	if(deck.size() == cards.size())
	{
		rpn(deck);
	}
	else
	{
		for(int i = 0; i < cards.size(); ++i)
		{
			if(!usedCards[i])
			{
				usedCards[i] = true;
				deck.push_back(cards[i]);
				shuffle(cards,deck,usedCards);
				deck.pop_back();
				usedCards[i] = false;
			}
		}
	}
}

int main()
{
	int N = 0;
	cin >> N;

	for(int i = 0; i < N; ++i)
	{
		vector<int> cards;
		for(int j = 0; j < 4; ++j)
		{
			int card = 0;
			cin >> card;
			cards.push_back(card);
		}

		vector<bool> usedCards(4,false);
		vector<int> deck;

		shuffle(cards,deck,usedCards);

		cout << answer << endl;
		answer = 0;
	}
	
	return 0;
}
