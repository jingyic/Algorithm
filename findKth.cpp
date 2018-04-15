#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &v, int low, int high)
{
	/*int p = v[high];
	int i = low - 1;
	for (int j = low; j < high; j++)
	{
		if (v[j] < p)
		{
			i = i + 1;
			swap(v[i], v[j]);
		}
	}
	swap(v[high], v[i + 1]);
	return i + 1;*/
	int first = low;
	int last = high;
	int p = v[first];

	while (first < last)
	{
		if (v[last] > p&&first < last)
			--last;
		swap(v[first], v[last]);

		if (v[first] < p&&first < last)
			++first;
		swap(v[first], v[last]);
	}
	return first;

}

int quickselection(vector<int> &v, int low, int high, int k)
{
	if (high == low) return v[low];

	int q = partition(v, low, high);
	if (q == k - 1+low) return v[q];
	else if (q > k + low - 1)
		quickselection(v, low, q - 1, k);
	else
		quickselection(v, q + 1, high, k + low - q - 1);

}
//

int main()
{
	int s,k,size;
	cin >> s;
	size = s;
	cin >> k;
	vector<int> v;
	while (s--)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	/*Finder solution;
	int n = solution.findKth(v, size,k);*/
	int n = quickselection(v, 0, size - 1, k);
	cout << n << endl;
	v.clear();
	return 0;
}