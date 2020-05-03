#include <iostream>
#include <vector>

using namespace std;
int n;
int score[21][21] = { 0 };
int smallest = -1;

void dfs(int cnt, int a, int b,vector<int> aa, vector<int> bb)
{
	if (cnt >= n)
	{
		if (a > b)
		{
			if (smallest == -1 || (a - b) < smallest)
				smallest = (a - b);
		}
		else
		{
			if (smallest == -1 || (b - a) < smallest)
				smallest = (b - a);
		}
		return;
	}

	//a에 넣고
	int temp = 0;
	if (aa.size() < n / 2)
	{
		for (int i = 0; i < aa.size(); i++)
		{
			temp += score[aa[i]][cnt];
			temp += score[cnt][aa[i]];
		}
		aa.push_back(cnt);
		dfs(cnt + 1, a + temp, b, aa, bb);
		aa.pop_back();
	}

	//b에 넣고
	if (bb.size() < n / 2)
	{
		temp = 0;
		for (int i = 0; i < bb.size(); i++)
		{
			temp += score[bb[i]][cnt];
			temp += score[cnt][bb[i]];
		}
		bb.push_back(cnt);
		dfs(cnt + 1, a, b + temp, aa, bb);
		bb.pop_back();
	}

}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int x;
			cin >> x;
			score[i][j] = x;
		}
	}

	vector<int> aa;
	vector<int> bb;
	dfs(0, 0, 0, aa, bb);
	cout << smallest;
	return 0;
}