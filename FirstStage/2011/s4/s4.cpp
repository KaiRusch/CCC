#include <stdio.h>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	//Arrays containing the units of blood and recipients
	// 0 = O- 1 = O+ 2 = A- 3 = A+ 4 = B- 5 = B+ 6 = AB- 7 = AB+
	int blood[8] = {0};
	int recipients[8] = {0};

	//Read the units of blood per blood type
	for(int i = 0; i < 8; ++i)
	{
		int units = 0;
		scanf("%d",&units);
		blood[i] = units;
	}

	//Read the number of recipients per blood type
	for(int i = 0; i < 8; ++i)
	{
		int people = 0;
		scanf("%d",&people);
		recipients[i] = people;

	}

	int transfers = 0;
	
	for(int i = 0; i < recipients[0]; ++i)
	{
		if(blood[0] > 0)
		{
			transfers++;
			blood[0]--;
		}
	}
	for(int i = 0; i < recipients[1]; ++i)
	{
		if(blood[1] > 0)
		{
			transfers++;
			blood[1]--;
		}
		else if(blood[0] > 0)
		{
			transfers++;
			blood[0]--;
		}
	}
	for(int i = 0; i < recipients[2]; ++i)
	{
		if(blood[2] > 0)
		{
			transfers++;
			blood[2]--;
		}
		else if(blood[0] > 0)
		{
			transfers++;
			blood[0]--;
		}
	}
	for(int i = 0; i < recipients[3]; ++i)
	{
		if(blood[3] > 0)
		{
			transfers++;
			blood[3]--;
		}
		else if(blood[2] > 0)
		{
			transfers++;
			blood[2]--;
		}
		else if(blood[1] > 0)
		{
			transfers++;
			blood[1]--;
		}
		else if(blood[0] > 0)
		{
			transfers++;
			blood[0]--;
		}
	}
	for(int i = 0; i < recipients[4]; ++i)
	{
		if(blood[4] > 0)
		{
			transfers++;
			blood[4]--;
		}
		else if(blood[0] > 0)
		{
			transfers++;
			blood[0]--;
		}
	}
	for(int i = 0; i < recipients[5]; ++i)
	{
		if(blood[5] > 0)
		{
			transfers++;
			blood[5]--;
		}
		else if(blood[4] > 0)
		{
			transfers++;
			blood[4]--;
		}
		else if(blood[1] > 0)
		{
			transfers++;
			blood[1]--;
		}
		else if(blood[0] > 0)
		{
			transfers++;
			blood[0]--;
		}
	}
	for(int i = 0; i < recipients[6]; ++i)
	{
		if(blood[6] > 0)
		{
			transfers++;
			blood[6]--;
		}
		else if(blood[4] > 0)
		{
			transfers++;
			blood[4]--;
		}
		else if(blood[2] > 0)
		{
			transfers++;
			blood[2]--;
		}
		else if(blood[0] > 0)
		{
			transfers++;
			blood[0]--;
		}
	}

	for(int i = 0; i < recipients[7]; ++i)
	{
		if(blood[7] > 0)
		{
			transfers++;
			blood[7]--;
		}
		else if(blood[6] > 0)
		{
			transfers++;
			blood[6]--;
		}
		else if(blood[5] > 0)
		{
			transfers++;
			blood[5]--;
		}
		else if(blood[4] > 0)
		{
			transfers++;
			blood[4]--;
		}
		else if(blood[3] > 0)
		{
			transfers++;
			blood[3]--;
		}
		else if(blood[2] > 0)
		{
			transfers++;
			blood[2]--;
		}
		else if(blood[1] > 0)
		{
			transfers++;
			blood[1]--;
		}
		else if(blood[0] > 0)
		{
			transfers++;
			blood[0]--;
		}
	}

	printf("%d\n",transfers);

	return 0;
}
