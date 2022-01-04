// C++ implementation of the approach
#include<bits/stdc++.h>
using namespace std;

// First segment's end index
static int pos1 = -1;

// Third segment's start index
static int pos2 = -1;

// This function returns true if the array
// can be divided into three equal sum segments
bool equiSumUtil(int arr[],int n)
{

	// Prefix Sum Array
	int pre[n];
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
		pre[i] = sum;
	}

	// Suffix Sum Array
	int suf[n];
	sum = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		sum += arr[i];
		suf[i] = sum;
	}

	// Stores the total sum of the array
	int total_sum = sum;

	int i = 0, j = n - 1;
	while (i < j - 1)
	{

		if (pre[i] == total_sum / 3)
		{
				pos1 = i;
		}

		if (suf[j] == total_sum / 3)
		{
			pos2 = j;
		}

		if (pos1 != -1 && pos2 != -1)
		{

			// We can also take pre[pos2 - 1] - pre[pos1] ==
			// total_sum / 3 here.
			if (suf[pos1 + 1] - suf[pos2] == total_sum / 3)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		if (pre[i] < suf[j])
		{
			i++;
		}
		else
		{
			j--;
		}
	}

	return false;
}

void equiSum(int arr[],int n)
{
	bool ans = equiSumUtil(arr,n);
	if (ans)
	{

		cout << "First Segment : ";
		for (int i = 0; i <= pos1; i++)
		{
			cout << arr[i] << " ";
		}

		cout << endl;

		cout << "Second Segment : ";
		for (int i = pos1 + 1; i < pos2; i++)
		{
			cout << arr[i] << " ";
		}

		cout << endl;

		cout << "Third Segment : ";
		for (int i = pos2; i < n; i++)
		{
			cout << arr[i] << " ";
		}

		cout<<endl;
	}
	else
	{
		cout << "Array cannot be divided into three equal sum segments";
	}
}
	
// Driver code
int main()
{
	int arr[] = { 1, 3, 6, 2, 7, 1, 2, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	equiSum(arr,n);
	return 0;
}

// This code is contributed by mits
