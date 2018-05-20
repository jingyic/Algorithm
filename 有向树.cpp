#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
#define maxnum 100000

int root,depth,len;
bool point[maxnum];
int pointindex = 0;
int From[maxnum];
//int To[maxnum];

struct edge {
	int from, to;

}Edge[maxnum];

void addedge(int x,int y,int to[])
{
	Edge[++pointindex].to = y;
	Edge[pointindex].from = From[x];
	From[x] = pointindex;
}

void computedepth(int root, int d)
{
	depth = max(depth, d);
	int i = From[root];
	while (i)
	{
		computedepth(Edge[i].to, d + 1);
		i = Edge[i].from;
	}
}
int main()
{
	int n, x, y;
	len = 0;
	int to[100000] = {0};
	int maxNum = 0;
	cin >> n;
	while (n--)
	{
		cin >> x >> y;
		addedge(x, y,to);
		point[x] = 1;
		point[y] = 1;
		to[y] = to[y] + 1;
		maxNum = max(maxNum, max(x, y));
	}

	int cntroot = 0;
	int cntto = 0;
	for (int i = 0; i <= maxNum; i++)
	{
		if (point[i] == 1)
		{
			len++;
			if (to[i] == 0)
			{
				cntroot++;
				root = i;
			}
			else if(to[i] == 1)
				cntto++;
		}
	}
		if (cntroot != 1)
			cout << "not tree 1" << endl;
		else if (cntto != len - 1)
			cout << "not tree 2" << endl;
		else
		{
			depth = 0;
			computedepth(root, 1);
			cout << "tree " << depth << endl;
		}
	//}
    return 0;
}

