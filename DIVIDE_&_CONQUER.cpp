#include <iostream>
using namespace std;
void Eval_Min(int arr[], int a, int b, int& min)
{
	if (a == b)			// COMPARE IN CASE OF ONE ELEMENT
	{
		    if (min > arr[b])	
			min = arr[b];
		return;
	}
	if (b-a == 1)			// COMPARE IN CASE OF TWO ELEMENTS
	{
		if (arr[a] < arr[b])	
		{
			if (min > arr[a])	
				min = arr[a];
		}
		else
		{
			if (min > arr[b])	
				min = arr[b];
		}
		return;
	}
	int mid = (a + b) / 2; //middle element
	Eval_Min(arr, a, mid, min); // recursion for left sub-array
    Eval_Min(arr, mid + 1, b, min); // recursion for right sub-array
}
int main()
{
	int arr[] = { 27, 32, 99, 65, 56, 76, 27, 88, 42};
	int n = sizeof(arr) / sizeof(arr[0]);

	int max = INT_MIN, min = INT_MAX;

	Eval_Min(arr, 0, n - 1, min);

	cout << "The minimum element in the array is " << min << '\n';
	return 0;
}
