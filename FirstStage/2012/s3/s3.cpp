#include <iostream>
#include <cmath>

using namespace std;

class Reading
{
	public:
		int reading;
		int frequency;

		Reading() {reading = 0; frequency = 0;};
		Reading(int r, int f) {reading = r; frequency = f;};
};

int main()
{
	
	Reading readings[1000];

	for(int i = 0; i < 1000; ++i)
	{
		readings[i] = Reading(i+1,0);
	}

	int N = 0;
	cin >> N;

	for(int i = 0; i < N; ++i)
	{
		int reading = 0;
		cin >> reading;
		readings[reading-1].frequency++;
	}

	for(int i = 1; i < 1000; ++i)
	{
		Reading note = readings[i];
		int j = i-1;
		while(j >= 0 &&((readings[j].frequency <  note.frequency) || (readings[j].frequency == note.frequency && readings[j].reading < note.reading)))
		{
			readings[j+1] = readings[j];
			j--;
		}
		
		readings[j+1] = note;
	}

	if(readings[0].frequency == readings[1].frequency)
	{
		int i = 1;
		int max = 0;
		while(readings[i].frequency == readings[i-1].frequency)
		{
			max = readings[0].reading - readings[i].reading;
			i++;
		}

		cout << max << endl;

	}
	else if(readings[1].frequency != readings[2].frequency)
	{
		cout << abs(readings[0].reading - readings[1].reading) << endl;
	}
	else
	{
		int max = abs(readings[0].reading - readings[1].reading);
		int i = 2;
		while(readings[i-1].frequency == readings[i].frequency)
		{
			if(abs(readings[0].reading - readings[i].reading) > max)
			{
				max = abs(readings[0].reading - readings[i].reading);
			}
			i++;
		}

		cout << max << endl;
	}

	return 0;
}
