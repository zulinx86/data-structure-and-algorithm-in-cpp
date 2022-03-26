/*
 * Insertion Sort
 * N: the number of items in the given array
 * Time complexity: O(N^2)
 * Space complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <random>

using namespace std;

void show(const vector<int> &arr) {
	for (int val : arr)
		cout << val << " ";
	cout << endl;
}

void insertion_sort(vector<int> &arr, const int n) {
	for (int i = 1; i < n; ++i) {
		int val = arr[i];

		int j;
		for (j = i; j > 0; --j) {
			if (arr[j - 1] > val)
				arr[j] = arr[j - 1];
			else
				break;
		}
		arr[j] = val;
	}
}

int main() {
	int n;
	cin >> n;

	vector<int> arr(n);
	random_device rnd;
	for (int i = 0; i < n; ++i)
		arr[i] = rnd() % 100;

	cout << "before: ";
	show(arr);

	insertion_sort(arr, n);

	cout << "after: ";
	show(arr);

	return 0;
}