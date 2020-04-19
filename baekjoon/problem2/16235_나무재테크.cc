#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int f[11][11] = { 0 };
int a[11][11]; //양분
vector<vector<int>> tree;

void spring_summer()
{
	int temp[11][11] = { 0 };
	for (int i = 0; i < tree.size(); i++)
	{
		if(tree[i].size()>1)
			sort(tree[i].begin(), tree[i].end());
		bool flag = false;
		vector<int> d_tree;
		for (int j = 1; j < tree[i].size(); j++)
		{
			if (flag == true)
			{
				temp[i / n][i%n] += tree[i][j] / 2;
				d_tree.push_back(j);
			}
			else
			{
				if (tree[i][j] <= f[i / n][i%n])
				{
					f[i / n][i%n] -= tree[i][j];
					tree[i][j]++;
				}
				else
				{
					temp[i / n][i%n] += tree[i][j] / 2;
					d_tree.push_back(j);
					flag = true;
				}
			}
		}
		int cnt = 0;
		for (int j = 0; j < d_tree.size(); j++)
		{
			tree[i].erase(tree[i].begin() + d_tree[j] + cnt);
			cnt--;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			f[i][j] += temp[i][j];
		}
	}
}
void fall()
{
	int dx[] = { -1,-1,-1,0,0,1,1,1 };
	int dy[] = { -1,0,1,-1,1,-1,0,1 };
	for (int i = 0; i < tree.size(); i++)
	{
		for (int j = 1; j < tree[i].size(); j++)
		{
			if (tree[i][j] % 5 == 0)
			{
				int r = i / n;
				int c = i%n;
				for (int k = 0; k < 8; k++)
				{
					int xx = r + dx[k];
					int yy = c + dy[k];
					if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
					tree[xx*n + yy].push_back(1);
				}
			}
		}
	}
}
void winter()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			f[i][j] += a[i][j];
		}
	}
}
int calc()
{
	int ans = 0;
	for (int i = 0; i < tree.size(); i++)
	{
		ans+=tree[i].size() - 1;
	}
	return ans;
}
void print()
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << f[i][j] << ' ';

		}
		cout << endl;
	}
	cout << endl;
}
int main()
{
	int m, k;
	cin >> n >> m >> k;
	vector<int> vv;
	vv.push_back(0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			tree.push_back(vv);
			f[i][j] = 5;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int x, y, age;
		cin >> x >> y >> age;
		tree[(x-1)*n + (y-1)].push_back(age);
	}
	
	for (int i = 0; i < k; i++)
	{
		//봄
		//여름
		spring_summer();

		//가울
		fall();

		//겨울
		winter();
	}

	cout << calc() << '\n';
	return 0;
}