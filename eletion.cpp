#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
int partition(int a[], int start,int end)
{
	int r = end;
	int i = start - 1;
	for (int p = start; p < end - 1; p++)
	{
		if (a[p] < a[r])
		{
			i++;
			swap(a[i], a[p]);
		}

	}
	swap(a[i + 1], a[r]);
	return i + 1;
}
int findKth(int a[], int low,int high, int k)
{
	if (low == high) return a[low];
	int q = partition(a, low, high);

	if (q == k - 1 + low) return a[q];
	else if (q > k - 1 + low)
		findKth(a, low, q - 1, k);
	else
		findKth(a, q + 1, high, k - q + low - 1);

}

int eletion(int a[][2], int num, int k)
{
	int temp[50000];
	for (int i = 0; i < num; i++)
	{
		temp[i] = a[i][0];
	}
	
	int m = findKth(temp, 0, num-1, k);
	
	for (int i = 0; i < num; i++)
	{
		if (a[i][0] < m)
			a[i][1] = 0;
	}
	int max = a[0][1];
	int index;
	for (int i = 1; i < num; i++)
	{
		if (a[i][1] > max)
		{
			max = a[i][1];
			index = i;
		}
	}
	return index+1;
}

int main()
{
	int N, k;
	cin >> N;
	cin >> k;
	int n = N;
	int cow[50000][2];
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a;
		cin >> b;
		cow[i][0] = a;
		cow[i][1] = b;
	}
	
	
	int index = eletion(cow, N, N-k+1);
	cout << index << endl;

	return 0;
}