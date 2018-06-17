#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include<cstdio>  
#include<cstring> 

using namespace std;
double dp[3000002];
int main()
{
	float total;
	int n;
	
	cin >> total >> n;
	while (n)
	{
		int a, b, c;
		int sign = 1;
		memset(dp, 0, sizeof(dp));
		vector<int> v;
		int t = int(total * 100);
		
		for (int i = 0; i < n;i++)
		{
			a = b = c = 0;
			int k;
			cin >> k;
			while (k--)
			{
				float x;
				char ch,str;
				cin >> ch >>str>> x;
				int s = int(x * 100);
				if (ch == 'A'&&a + s <= 60000)
				{
					a = a + s;
				}
				else if (ch == 'B' && b + s <= 60000)
					b = b + s;
				else if (ch == 'C' && c + s <= 60000)
					c = c + s;
				else
					sign = 0;
			}
			if (sign == 1 && (a + b + c) <= 100000)
				v.push_back(a + b + c);
			
			//cin >> total >> n;
		}
		/*for (int j = 0; j <= t; j++)
		{
			if (j < v[0])
				dp[0][j] = 0;
			else
				dp[0][j] = v[0];
		}*/
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = t; j >= v[i]; j--)
			{
				//if (j >= v[i])
					dp[j] = max(dp[j], dp[j - v[i]] + v[i]);
			}
		}
		
		float res = dp[t] / 100.00;
		printf("%.2f\n", res);
		v.clear();
		cin >> total >> n;
	}
	
	return 0;
}