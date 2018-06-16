#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

void maxsum(vector<int> &v,int outarr[])
{
	int arr[100000];
	int idx[100000][2];
	
	idx[0][0] = 0;
	idx[0][1] = 0;
	arr[0] = v[0];

	for (int i = 1; i < v.size(); i++)
	{
		if (arr[i - 1] + v[i] >= v[i])
		{
			arr[i] = arr[i - 1] + v[i];
			idx[i][0] = idx[i - 1][0];
			idx[i][1] = i;
		}
		else
		{
			arr[i] = v[i];
			idx[i][0] = i;
			idx[i][1] = i;
		}
	}
	outarr[0] = arr[0];
	outarr[1] = idx[0][0]+1;
	outarr[2] = idx[0][1]+1;
	for (int i = 1; i < v.size(); i++)
	{
		if (arr[i] > outarr[0])
		{
			outarr[0] = arr[i];
			outarr[1] = idx[i][0]+1;
			outarr[2] = idx[i][1]+1;
		}
	}
}
int main()
{
	int inputnum = 0;
	cin >> inputnum;
	int input[20][100000];
	for (int i = 1; i <= inputnum; i++)
	{
		int n;
		cin >> n;
		input[i][0] = n;
		int j = 1;
		while (n--)
		{
			int x;
			cin >> x;
			input[i][j] = x;
			j++;
		}
	}
	for (int i = 1; i <= inputnum; i++)
	{
		
		int outarr[3];
		vector<int> v;
		for (int j = 1; j <= input[i][0]; j++)
		{
			v.push_back(input[i][j]);
		}
		
		maxsum(v, outarr);
		v.clear();
		if (i < inputnum)
		{
			cout << "Case " << i << ":" << endl;
			cout << outarr[0] << " " << outarr[1] << " " << outarr[2] << endl << endl;
		}
		else
		{
			cout << "Case " << i << ":" << endl;
			cout << outarr[0] << " " << outarr[1] << " " << outarr[2] << endl;
		}
	}
    return 0;
}