// work3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

void cowsort(int a[],int size,int v[])
{
	int j = 1;
	int num = size;

	while (num--)
	{
		for (int i = size - 1; i >= 0; i--)
		{
			if (v[i] == 0)
			{
				a[i] = j;
				j++;
				for (int m = i; m < size; m++)
				{
					v[m]--;
				}
				break;
			}
		}
	}
	
	

}

int main()
{
	int size;
	cin >> size;
	
	int cow[10000];
	int v[10000];
	v[0] = 0;
	for (int i = 1; i < size; i++)
	{
		int a;
		cin >> a;
		v[i] = a;
	}
	
	cowsort(cow, size, v);
	for (int i = 0; i < size; i++)
	{
		cout << cow[i] << endl;
	}
    return 0;
}

