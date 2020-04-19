#include <iostream>

using namespace std;

int main()
{
	int n, m, x, y, k;
	cin >> n >> m >> x >> y >> k;
	int map[21][21];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	}
	int dice[7] = { 0 };
	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { 1,-1,0,0 };
	for (int i = 0; i < k; i++)
	{
		int move;
		cin >> move;
		int xx = x + dx[move - 1];
		int yy = y + dy[move - 1];
		if (xx < 0 || xx >= n || yy < 0 || yy >= m)
			continue;
		else
		{
			x = xx;
			y = yy;
			if (move == 1)
			{
				int temp = dice[1];
				dice[1] = dice[4];
				dice[4] = dice[6];
				dice[6] = dice[3];
				dice[3] = temp;
			}
			else if (move == 2)
			{
				int temp = dice[1];
				dice[1] = dice[3];
				dice[3] = dice[6];
				dice[6] = dice[4];
				dice[4] = temp;
			}
			else if (move == 3)
			{
				int temp = dice[1];
				dice[1] = dice[5];
				dice[5] = dice[6];
				dice[6] = dice[2];
				dice[2] = temp;
			}
			else
			{
				int temp = dice[1];
				dice[1] = dice[2];
				dice[2] = dice[6];
				dice[6] = dice[5];
				dice[5] = temp;
			}
		}
		if (map[x][y] == 0)
		{
			map[x][y] = dice[6];
		}
		else
		{
			dice[6] = map[x][y];
			map[x][y] = 0;
		}
		cout << dice[1] << endl;
	}
	return 0;
}