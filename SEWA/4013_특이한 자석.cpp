#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>

using namespace std;
int roller[4][8];

int check()
{
	int ans = 0;
	if (roller[0][0] == 1)
		ans += 1;
	if (roller[1][0] == 1)
		ans += 2;
	if (roller[2][0] == 1)
		ans += 4;
	if (roller[3][0] == 1)
		ans += 8;
	return ans;
}
void rotate(int num, int dir)
{
	if (dir == 1)
	{
		int temp = roller[num][7];
		for (int i = 7; i >0; i--)
		{
			roller[num][i] = roller[num][(i -1) % 8];
		}
		roller[num][0] = temp;
	}
	else
	{
		int temp = roller[num][0];
		for (int i = 0; i < 7; i++)
		{
			roller[num][i] = roller[num][(i + 1) % 8];
		}
		roller[num][7] = temp;
	}
}
void sim(int num, int dir)
{
	if (num == 1)
	{
		bool f1 = false, f2 = false, f3 = false;
		if (roller[0][2] != roller[1][6])
			f1 = true;
		if (roller[1][2] != roller[2][6])
			f2 = true;
		if (roller[2][2] != roller[3][6])
			f3 = true;
		if (dir == 1)//시계
		{
			rotate(0, 1);
		}
		else //반시계
		{
			rotate(0, -1);
		}
		//234
		if (f1 == true)
		{
			dir = -dir;
			rotate(1, dir);
		}
		else
			return;
		if (f2 == true)
		{
			dir = -dir;
			rotate(2, dir);
		}
		else
			return;
		if (f3 == true)
		{
			dir = -dir;
			rotate(3, dir);
		}
		else
			return;
	}
	else if (num == 2)
	{
		bool f1 = false, f2 = false, f3 = false;
		if (roller[0][2] != roller[1][6])
			f1 = true;
		if (roller[1][2] != roller[2][6])
			f2 = true;
		if (roller[2][2] != roller[3][6])
			f3 = true;
		if (dir == 1)//시계
		{
			rotate(1, 1);
		}
		else //반시계
		{
			rotate(1, -1);
		}
		//1 23
		if (f1==true)
		{
			int t_dir = -dir;
			rotate(0, t_dir);
		}
		if (f2 == true)
		{
			dir = -dir;
			rotate(2, dir);
		}
		else
			return;
		if (f3 == true)
		{
			dir = -dir;
			rotate(3, dir);
		}
		else
			return;
	}
	else if (num == 3)
	{
		bool f1 = false, f2 = false, f3 = false;
		if (roller[2][2] != roller[3][6])
			f1 = true;
		if (roller[1][2] != roller[2][6])
			f2 = true;
		if (roller[0][2] != roller[1][6])
			f3 = true;
		if (dir == 1)//시계
		{
			rotate(2, 1);
		}
		else //반시계
		{
			rotate(2, -1);
		}
		//21 4
		if (f1==true)
		{
			int t_dir = -dir;
			rotate(3, t_dir);
		}
		if (f2 == true)
		{
			dir = -dir;
			rotate(1, dir);
		}
		else
			return;
		if (f3 == true)
		{
			dir = -dir;
			rotate(0, dir);
		}
		else
			return;
	}
	else
	{
		bool f1 = false, f2 = false, f3 = false;
		if (roller[2][2] != roller[3][6])
			f1 = true;
		if (roller[1][2] != roller[2][6])
			f2 = true;
		if (roller[0][2] != roller[1][6])
			f3 = true;
		if (dir == 1)//시계
		{
			rotate(3, 1);
		}
		else //반시계
		{
			rotate(3, -1);
		}
		//321
		if (f1==true)
		{
			dir = -dir;
			rotate(2, dir);
		}
		else
			return;
		if (f2 == true)
		{
			dir = -dir;
			rotate(1, dir);
		}
		else
			return;
		if (f3 == true)
		{
			dir = -dir;
			rotate(0, dir);
		}
		else
			return;
	}
	return;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int k;
		cin >> k;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
				cin >> roller[i][j];
		}
		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;
			sim(x, y);
		}
		cout << '#' << test_case << ' ' << check() << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}