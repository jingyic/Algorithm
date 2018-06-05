#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

#define MAX 100000
#define INF 1000000
vector<int> G[MAX];
vector<int> E[MAX];
bool visit[MAX];
int d[MAX];

void DFS(int n)
{
	visit[n] = 1;
	int size = G[n].size();
	for (int i = 0; i < size; i++)
	{
		int v = G[n][i];
		if (visit[v] == 0)
		{
			d[v] = d[n] + 1;
			DFS(v);
			
		}
			
	}

}
int main()
{
	int n;
	cin >> n;
	int u, v;
	for (int i = 0; i < n-1; i++)
	{
		cin >> u >> v;
		G[u - 1].push_back(v - 1);
		G[v - 1].push_back(u - 1);
	}
	for (int i = 0; i < n; i++)
	{
		visit[i] = 0;
		//d[i] = (i == 0 ? 0 : INF);
		d[i] = 0;
	}
	DFS(0);
	int start = 0;
	int max = -1;
	for (int i = 0; i < n; i++)
	{
		if (d[i] > max&&d[i] != INF)
		{
			max = d[i];
			start = i;
		}
	}
	for (int i = 0; i < n; i++)
	{
		visit[i] = 0;
		//d[i] = (i == start ? 0 : INF);
		d[i] = 0;
	}
	DFS(start);
	int ans = -1;
	for (int i = 0; i < n; i++)
	{
		if (d[i] > ans&&d[i] != INF)
		{
			ans = d[i];
		}
	}
	cout << ans << endl;
	return 0;


}