#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

double findKth(vector<int> &arr1, vector<int> &arr2, int low1,int low2,int k)
{
	int k1 = arr1.size() - low1;
	int k2 = arr2.size() - low2;
	
	if (k1 > k2)
		return findKth(arr2, arr1, low2, low1, k);
	if (k1 == 0)
		return arr2[low2 + k - 1];
	if (k == 1)
		return min(arr1[low1], arr2[low2]);

	int p = min(k/2,k1);
	int q = k - p;
	/*if (p < k1)
	{*/
		if (arr1[low1 + p - 1] < arr2[low2 + q - 1])
			return findKth(arr1, arr2, low1 + p, low2, k - p);
		else if (arr1[low1 + p - 1] > arr2[low2 + q - 1])
			return findKth(arr1, arr2, low1, low2 + q, k - q);
		else
			return arr1[low1 + p - 1];
	//}

}

double getMid(vector<int> &arr1, vector<int> &arr2)
{
	int k = (arr1.size() + arr2.size()) / 2;
	int m = arr1.size();
	int n = arr2.size();

	if ((m + n) % 2 == 0)
		return (findKth(arr1, arr2,0,0, k) + findKth(arr1, arr2,0,0, k + 1)) / 2;
	else
		return findKth(arr1, arr2,0,0, k + 1);
	
}

int main()
{
	int m, n;
	cin >> m;
	cin >> n;
	vector<int> arr1;
	vector<int> arr2;
	while (m--)
	{
		int a;
		cin >> a;
		arr1.push_back(a);
	}
	while (n--)
	{
		int b;
		cin >> b;
		arr2.push_back(b);
	}

	double median = getMid(arr1, arr2);
	cout << median << endl;

	return 0;
}