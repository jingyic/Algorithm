// HW5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

#define MAX 100

vector<int> Graph[MAX];
vector<int> graph[MAX];
int visit[MAX];
int cnt[MAX];
stack<int> s;

int ccnt = 0;

void DFS(int n)
{
	visit[n] = 1;
	vector<int>::iterator iter;
	for (iter = Graph[n].begin(); iter != Graph[n].end(); iter++)
	{
		if (visit[*iter] == 0)
			DFS(*iter);
	}
	s.push(n);
}
void DFS_wapper(int n)
{
	for (int i = 0; i < n; i++)
	{
		if (visit[i] == 0)
			DFS(i);
	}
}

void dfs(int n,int head)
{
	visit[n] = 1;
	vector<int>::iterator iter;
	for (iter = graph[n].begin(); iter != graph[n].end(); iter++)
	{
		if (visit[*iter] == 0)
			dfs(*iter, head);
	}
	cnt[n] = head;

}
void dfs_wapper(int n)
{
	for (int i = 1; i <= n; i++)
	{
		visit[i] = 0;
	}
	while (!s.empty())
	{
		int a = s.top();
		s.pop();
		if (visit[a] == 0)
		{
			ccnt++;
			dfs(a, ccnt);

		}
	}
}

void solution(int n, int in[],int out[])
{
	DFS_wapper(n);
	dfs_wapper(n);
	for (int i = 1; i <= ccnt; i++)
	{
		in[i] = 0;
		out[i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		vector<int>::iterator iter;
		for (iter = Graph[i].begin(); iter != Graph[i].end(); iter++)
		{
			if (cnt[i] != cnt[*iter])
			{
				out[cnt[i]]++;
				in[cnt[*iter]]++;
			}
		}
	}

}
int main()
{
	int n,ansA,ansB;
	int in[MAX];
	int out[MAX];
	cin >> n;
	for(int i = 1;i <= n; i++)
	{
		int a;
		cin >> a;
		while (a)
		{
			Graph[i].push_back(a);
			cin >> a;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		vector<int>::iterator iter;

		for (iter = Graph[i].begin(); iter != Graph[i].end(); iter++)
		{
			graph[*iter].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		visit[i] = 0;
	}
	//while (!s.empty())
	//	s.pop();
	solution(n, in, out);
	ansA = 0;
	ansB = 0;
	for (int i = 1; i <= ccnt; i++)
	{
		if (!in[i])
			ansA++;
		if (!out[i])
			ansB++;
	}
	int ans = max(ansA, ansB);
	if (ccnt == 1)
		cout << "1" << endl << "0" << endl;
	else
		cout << ansA << endl << ans << endl;
    return 0;
}

