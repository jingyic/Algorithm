#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int maxsum(vector<int> &v)
{
	//int m = -10000;
	int dp[1000];
	//dp[0] = v[0];
	for (int i = 0; i < v.size(); i++)
	{
		dp[i] = v[i];
	}
	for (int i = 1; i < v.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[i] > v[j] && (dp[j] + v[i]) > dp[i])
				dp[i] = dp[j] + v[i];
		}
	}
	int m = dp[0];
	for (int i = 1; i < v.size(); i++)
	{
		if (dp[i] > m)
			m = dp[i];
	}
	return m;
}
int main()
{
	int n;
	cin >> n;
	while (n)
	{
		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			v.push_back(x);
		}
		int res = maxsum(v);
		v.clear();
		cout << res << endl;
		cin >> n;
	}
	return 0;
}