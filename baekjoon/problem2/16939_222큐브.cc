#include <iostream>

using namespace std;
int cube[25];

bool check()
{
	if (cube[5] == cube[6] && cube[6] == cube[7] && cube[7] == cube[8]
		&& cube[21] == cube[22] && cube[22] == cube[23] && cube[23] == cube[24])
	{
		if (cube[3] == cube[4] && cube[1] == cube[2] && cube[13] == cube[15]
			&& cube[14] == cube[16] && cube[9] == cube[10] && cube[11] == cube[12]
			&& cube[17] == cube[19] && cube[18] == cube[20])
		{
			if (cube[3] == cube[18] && cube[17] == cube[12] && cube[10] == cube[15] && cube[16] == cube[1])
				return true;
			else if (cube[3] == cube[15] && cube[16] == cube[12] && cube[10] == cube[18] && cube[17] == cube[1])
				return true;
		}
	}


	if (cube[13] == cube[14] && cube[14] == cube[15] && cube[15] == cube[16]
		&& cube[17] == cube[18] && cube[18] == cube[19] && cube[19] == cube[20])
	{
		if (cube[1] == cube[3] && cube[2] == cube[4] && cube[5] == cube[7]
			&& cube[6] == cube[8] && cube[9] == cube[11] && cube[10] == cube[12]
			&& cube[21] == cube[23] && cube[22] == cube[24])
		{
			if (cube[24] == cube[2] && cube[1] == cube[6] && cube[5] == cube[10] && cube[9] == cube[23])
				return true;
			else if (cube[23] == cube[1] && cube[2] == cube[5] && cube[6] == cube[9] && cube[10] == cube[24])
				return true;
		}
	}

	if (cube[1] == cube[2] && cube[2] == cube[3] && cube[3] == cube[4]
		&& cube[9] == cube[10] && cube[10] == cube[11] && cube[11] == cube[12])
	{
		if (cube[13] == cube[14] && cube[15] == cube[16] && cube[5] == cube[6]
			&& cube[7] == cube[8] && cube[17] == cube[18] && cube[19] == cube[20]
			&& cube[21] == cube[22] && cube[23] == cube[24])
		{
			if (cube[13] == cube[7] && cube[5] == cube[19] && cube[17] == cube[23] && cube[21] == cube[15])
				return true;
			else if (cube[5] == cube[15] && cube[13] == cube[23] && cube[21] == cube[19] && cube[17] == cube[7])
				return true;
		}
	}

	return false;
}

int main()
{
	for (int i = 0; i < 24; i++)
		cin >> cube[i + 1];
	
	if (check())
		cout << 1;
	else
		cout << 0;

}